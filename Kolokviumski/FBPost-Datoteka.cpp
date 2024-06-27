#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string username,content;
    int cases,isPhoto,likes,shares,retweets,replis;
    string line;
    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}


class Post {
protected:
    string username, content;
    bool isPhoto;
    int likes;
public:
    Post(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0)
            : username(username), content(content), isPhoto(isPhoto), likes(likes) {}

    virtual double popularity() const = 0;

    virtual void print(ostream &o) const {
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (isPhoto) {
            cout << "With photo: " << endl;
        } else {
            cout << "Without photo: " << endl;
        }
        cout << "Likes: " << likes;
    }

    bool hasPhoto() const {
        return isPhoto;
    }

    bool operator<(const Post &rhs) const {
        return popularity() < rhs.popularity();
    }

    bool operator>(const Post &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Post &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Post &rhs) const {
        return !(*this < rhs);
    }
};

class FacebookPost : public Post {
private:
    int shares;
public:
    FacebookPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                 int shares = 0)
            : Post(username, content, isPhoto, likes), shares(shares) {}

    double popularity() const override {
        double r = likes * shares;
        if (isPhoto) {
            r *= 1.2;
        }
        return r;
    }

    void print(ostream &o) const override {
        cout << "Facebook post: " << endl;
        Post::print(o);
        cout << " Shares: " << shares << endl;
        cout << popularity();
    }
};

class TwitterPost : public Post {
private:
    int retweets;
    int replies;
public:
    TwitterPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                int retweets = 0, int replies = 0)
            : Post(username, content, isPhoto, likes), replies(replies), retweets(retweets) {}

    double popularity() const override {
        double r = likes * retweets * replies;
        if (isPhoto) {
            r *= 1.1;
        }
        if (content.find("#crypto") != -1) {
            r *= 1.2;
        }
        return r;
    }

    void print(ostream &o) const override {
        cout << "Twitter post: " << endl;
        Post::print(o);
        cout << " Retweets: " << retweets << " Replies: " << replies << endl;
        cout << popularity();
    }
};

double mostPopularPostWithPhoto(Post **posts, int n) {
    double max;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (posts[i]->hasPhoto()) {
            if (!flag) {
                max = posts[i]->popularity();
                flag = true;
                continue;
            }
            if (posts[i]->popularity() >= max) {
                max = posts[i]->popularity();
            }
        }
    }
    return max;
}

Post *leastPopularTwitterPost(Post **posts, int n) {
    Post *leastPopular = nullptr;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<TwitterPost *>(posts[i])) {
            if (leastPopular == nullptr || posts[i]->popularity() < leastPopular->popularity()) {
                leastPopular = posts[i];
            }
        }
    }
    return leastPopular;
}

Post *readFbPost(istream &infile) {
    string username, content;
    bool isPhoto;
    int likes, shares;
    getline(infile, username);
    getline(infile, content);
    infile >> isPhoto >> likes >> shares;
    infile.ignore();
    return new FacebookPost(username, content, isPhoto, likes, shares);
}

Post *readTwPost(istream &infile) {
    string username, content;
    bool isPhoto;
    int likes, retweets, replies;
    getline(infile, username);
    getline(infile, content);
    cin >> isPhoto >> likes >> retweets >> replies;
    cin.ignore();
    return new TwitterPost(username, content, isPhoto, likes, retweets, replies);
}

Post **readMultPosts(istream &infile, int *n) {
    infile >> *n;
    infile.ignore();
    Post **posts = new Post *[*n];
    for (int i = 0; i < *n; ++i) {
        int type;
        infile >> type;
        infile.ignore();
        if (type == 1) {
            posts[i] = readFbPost(infile);
        } else {
            posts[i] = readTwPost(infile);
        }
    }
    return posts;
}

void writeToFile(ofstream &o, Post *post) {
    post->print(o);
}


int main() {
    wtf();

    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int testCase;
    inFile >> testCase;
    inFile.ignore();

    if (testCase == 1) {
        Post *post = readFbPost(inFile);
        outFile << "Testing FacebookPost: " << endl;
        outFile << "Popularity: " << post->popularity() << endl;
        writeToFile(outFile, post);
    } else if (testCase == 2) {
        Post *post = readTwPost(inFile);
        outFile << "Testing TwitterPost: " << endl;
        outFile << "Popularity: " << post->popularity() << endl;
        writeToFile(outFile, post);
    } else if (testCase == 3) {
        int n;
        Post **posts = readMultPosts(inFile, &n);
        outFile << "Testing operator >=" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*posts[i] >= (*posts[j]))) {
                        outFile << i << " >= " << j << endl;
                    } else {
                        outFile << i << " < " << j << endl;

                    }
                }
            }
        }
    } else {
        int n;
        Post **posts = readMultPosts(inFile, &n);
        for (int i = 0; i < n; ++i) {
            writeToFile(outFile, posts[i]);
            outFile << endl;
        }
        outFile << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n)
                << endl;

        outFile << "The least popular twitter post is: " << endl;
        Post *result= leastPopularTwitterPost(posts,n);
        if(result== nullptr){
            outFile<<"None";
        } else{
            writeToFile(outFile,result);
        }
    }

    inFile.close();
    outFile.close();
}
