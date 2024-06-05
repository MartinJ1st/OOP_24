#include <iostream>
#include <string>

using namespace std;

class Post {
protected:
    string username;
    string author;
    string content;
    bool slika;
    int brLajkovi;
public:
    Post(const string &username = "", const string &author = "", const string &content = "", bool slika = true,
         int brLajkovi = 0) {
        this->username = username;
        this->author = author;
        this->content = content;
        this->slika = slika;
        this->brLajkovi = brLajkovi;
    }

    virtual double popularity() const = 0;

    virtual void print() = 0;

    bool operator>=(Post &p) {
        return this->popularity() >= p.popularity();
    }

    bool isSlika() const {
        return slika;
    }
};

class FacebookPost : public Post {
private:
    int shares;
public:
    FacebookPost(const string &username = "", const string &author = "", const string &content = "", bool slika = true,
                 int brLajkovi = 0, int shares = 0) : Post(username, author, content, slika, brLajkovi) {
        this->shares = shares;
    }

    double popularity() override {
        double base = brLajkovi * shares;
        if (slika) {
            return base * 1.2;
        } else {
            return base;
        }
    }

    void print() override {
        cout << "Facebook post" << endl;
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (slika) {
            cout << "With photo" << endl;
        } else {
            cout << "Without photo" << endl;
        }
        cout << "Likes: " << brLajkovi << " " << " Shares: " << shares << endl;
        cout << "Popularity: " << popularity() << endl;
    }
};

class TwitterPost : public Post {
private:
    int retweets;
    int replies;
public:
    TwitterPost(const string &username = "", const string &author = "", const string &content = "", bool slika = true,
                int brLajkovi = 0, int retweets = 0, int replies = 0) : Post(username, author, content, slika,
                                                                             brLajkovi) {
        this->retweets = retweets;
        this->replies = retweets;

    }

    double popularity() override {
        double base = brLajkovi * retweets * replies;
        if (slika) {
            base *= 1.1;
        }
        if (content.find("#crypto") != -1) {
            return base * 1.2;
        }
        return base;
    }

    void print() override {
        cout << "TwitterPost post" << endl;
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (slika) {
            cout << "With photo" << endl;
        } else {
            cout << "Without photo" << endl;
        }
        cout << "Likes: " << brLajkovi << " " << " Retweets: " << retweets << " Replies: " << replies << endl;
        cout << "Popularity: " << popularity() << endl;
    }
};


double mostPopularPostWithPhoto(Post **posts, int n) {
    bool flag = true;
    double max = 0;
    for (int i = 0; i < n; ++i) {
        if (posts[i]->isSlika()) {
            if (flag) {
                max = posts[i]->popularity();
                flag = false;
                continue;

            }
            if (posts[i]->popularity() >= max) {
                max = posts[i]->popularity();
            }
        }
    }
    return max;
}

double mostPopularTwitterPost(Post **posts, int n) {
    bool flag = true;
    double max = 0;
    for (int i = 0; i < n; ++i) {
        TwitterPost*tmp=dynamic_cast<TwitterPost*>(posts[i]);
        if (tmp) {
            if (flag) {
                max = posts[i]->popularity();
                flag = false;
                continue;
            }
            if (posts[i]->popularity() >= max) {
                max = posts[i]->popularity();
            }
        }
    }
    return max;
}
