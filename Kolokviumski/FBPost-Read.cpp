#include <iostream>
#include <string>

using namespace std;

class Post {
protected:
    string username;
    string content;
    bool isPhoto;
    int likes;
public:
    Post(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0)
            : username(username), content(content), isPhoto(isPhoto), likes(likes) {}

    virtual double popularity() const = 0;

    virtual void print() {
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (isPhoto) {
            cout << "With photo" << endl;
        } else {
            cout << "Without photo" << endl;
        }
        cout << "Likes: " << likes;
    }

    bool operator>=(Post &p) {
        return this->popularity() >= p.popularity();
    }

    bool havePhoto() const {
        return isPhoto;
    }
};

class FacebookPost : public Post {
private:
    int shares;
public:
    FacebookPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                 int shares = 0)
            : Post(username, content, isPhoto, likes) {
        this->shares = shares;
    }

    double popularity() const override {
        double p = likes * shares;
        if (isPhoto) {
            p *= 1.2;
        }
        return p;
    }

    void print() override {
        cout << "Facebook post" << endl;
        Post::print();
        cout << " Shares: " << shares;
        cout << " Popularity: " << popularity();
    }
};

class TwitterPost : public Post {
private:
    int retweets;
    int replies;
public:
    TwitterPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                int retweets = 0, int replies = 0)
            : Post(username, content, isPhoto, likes) {
        this->retweets = retweets;
        this->replies = replies;
    }

    double popularity() const override {
        double p = likes * retweets * replies;
        if (isPhoto) {
            p *= 1.1;
        }
        if (content.find("#crypto") != -1) {
            p *= 1.2;
        }
        return p;
    }

    void print() override {
        cout << "Twitter post" << endl;
        Post::print();
        cout << " Retweets: " << retweets << " Replies: " << replies << endl;
        cout << "Popularity: " << popularity();
    }
};

double mostPopularPostWithPhoto(Post **posts, int n) {
    double max = -1;

    for (int i = 0; i < n; ++i) {
        if (posts[i]->havePhoto() && posts[i]->popularity() >= max) {
            max = posts[i]->popularity();
        }
    }
    return max;
}

Post *leastPopularTwitterPost(Post **posts, int n) {
    Post *least = nullptr;

    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<TwitterPost *>(posts[i])) {
            if (least == nullptr || posts[i]->popularity() < least->popularity()) {
                least = posts[i];
            }
        }
    }
    return least;
}


Post *readFbPost() {
    string username, content;
    bool isPhoto;
    int likes, shares;
    cin.ignore();
    getline(cin, username);
    getline(cin, content);
    cin >> isPhoto >> likes >> shares;
    return new FacebookPost(username, content, isPhoto, likes, shares);
}

Post *readTwPost() {
    string username, content;
    bool isPhoto;
    int likes, retweets, replies;
    cin.ignore();
    getline(cin, username);
    getline(cin, content);
    cin >> isPhoto >> likes >> retweets >> replies;
    return new TwitterPost(username, content, isPhoto, likes, retweets, replies);
}

Post **readMultPostes(int *n) {
    cin >> *n;
    Post **posts = new Post *[*n];
    for (int i = 0; i < *n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            posts[i] = readFbPost();
        } else {
            posts[i] = readTwPost();
        }
    }
    return posts;
}

int main() {
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test FacebookPost" << endl;
        Post *post = readFbPost();
        cout << "Popularity: " << post->popularity() << endl;
        post->print();
    } else if (testCase == 2) {
        cout << "Test TwitterPost" << endl;
        Post *post = readTwPost();
        cout << "Popularity: " << post->popularity() << endl;
        post->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        Post **posts = readMultPostes(&n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (*(posts[i]) >= *(posts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        Post **posts = readMultPostes(&n);
        for (int i = 0; i < n; ++i) {
            posts[i]->print();
            cout << endl;
        }
        cout << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n) << endl;
        cout << "The least popular twitter post is: " << endl;
            Post *result = leastPopularTwitterPost(posts, n);
        if (result == nullptr) {
            cout << "None";
        } else {
            result->print();
        }
    }
    return 0;
}