//write 5 more exercises and make sure: 2 of them have abstract classes with files and
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Post {
protected:
    string username, content;
    bool isPhoto;
    int likes;
public:
    Post(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0)
            : username(username), content(content), isPhoto(isPhoto), likes(likes) {}

    virtual double popularity() const = 0;

    virtual void print(ostream &out) const {
        out << "Username: " << username << endl;
        out << "Content: " << content << endl;
        if (isPhoto) {
            out << "With photo" << endl;
        } else {
            out << "Without photo" << endl;
        }
        cout << "Likes: " << likes;
    }

    bool operator<(const Post &rhs) const {
        return this->popularity() < rhs.popularity();
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

class FacebookPost : virtual public Post {
protected:
    int shares;
public:
    FacebookPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                 int shares = 0)
            : Post(username, content, isPhoto, likes), shares(shares) {}

    double popularity() const override {
        double p = likes * shares;
        if (isPhoto) {
            p *= 1.2;
        }
        return p;
    }

    void print(ostream &out) const override {
        out << "Facebook post" << endl;
        Post::print(out);
        out << " Shares: " << shares << endl;
        out << "Popularity: " << popularity() << endl;
    }
};

class TwitterPost : public virtual Post {
protected:
    int retweets;
    int replies;
public:
    TwitterPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
                int retweets = 0, int replies = 0)
            : Post(username, content, isPhoto, likes), replies(replies), retweets(retweets) {}

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

    void print(ostream &out) const override {
        out << "Facebook post" << endl;
        Post::print(out);
        out << " Retweets: " << retweets << " Replies: " << replies << endl;
        out << "Popularity: " << popularity() << endl;
    }
};

class PhotoPost : public FacebookPost, public TwitterPost {
public:
    PhotoPost(const string &username = "", const string &content = "", bool isPhoto = false, int likes = 0,
              int shares = 0, int retweets = 0, int replies = 0)
            : FacebookPost(username, content, isPhoto, likes, shares),
              TwitterPost(username, content, isPhoto, likes, retweets, replies) {}

    double popularity() const override {
        double pop = (FacebookPost::popularity() + TwitterPost::popularity()) / 2.0;
        if (likes < 1000) {
            pop *= 0.8;
        }
        return pop;
    }

    void print(ostream &out) const override {
        out << "Photo post" << endl;
        FacebookPost::print(out);
        TwitterPost::print(out);
        out << "New Popularity: " << popularity() << endl;
    }
};

class VideoPost : public FacebookPost, public TwitterPost {
private:
    int duration;
public:
    VideoPost(const string &username = "", const string &content = "", int likes = 0, bool hasPhoto = false,
              int shares = 0, int retweets = 0, int replies = 0, int duration = 0)
            : FacebookPost(username, content, likes, hasPhoto, shares),
              TwitterPost(username, content, likes, hasPhoto, retweets, replies), duration(duration) {}

    double popularity() const override {
        double pop = (FacebookPost::popularity() + TwitterPost::popularity()) / 2.0;
        return pop * (1 + (duration / 100.0));
    }

    void print(ostream &out) const override {
        out << "Video post" << endl;
        Post::print(out);
        out << "Shares: " << shares << " Retweets: " << retweets << " Replies: " << replies << endl;
        out << "Duration: " << duration << " seconds" << endl;
        out << "Combined Popularity: " << popularity() << endl;
    }
};

double mostPopularPostWithPhoto(Post **posts, int n) {
    double max = -1;
    for (int i = 0; i < n; ++i) {
        if (posts[i]->popularity() > max) {
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

Post *readPhotoPost(ifstream &infile) {
    string username;
    string content;
    int likes;
    int shares;
    int retweets;
    int replies;
    bool hasPhoto;
    getline(infile, username);
    getline(infile, content);
    infile >> likes >> shares >> retweets >> replies >> hasPhoto;
    infile.ignore();
    return new PhotoPost(username, content, likes, hasPhoto, shares, retweets, replies);
}

Post *readVideoPost(ifstream &infile) {
    string username;
    string content;
    int likes;
    int shares;
    int retweets;
    int replies;
    int duration;
    bool hasPhoto;
    getline(infile, username);
    getline(infile, content);
    infile >> likes >> shares >> retweets >> replies >> hasPhoto >> duration;
    infile.ignore();
    return new VideoPost(username, content, likes, hasPhoto, shares, retweets, replies, duration);
}

Post **readMultiplePosts(ifstream &infile, int *n) {
    infile >> *n;
    infile.ignore();
    Post **posts = new Post *[*n];
    for (int i = 0; i < *n; i++) {
        int type;
        infile >> type;
        infile.ignore();
        if (type == 1) {
            posts[i] = readPhotoPost(infile);
        } else {
            posts[i] = readVideoPost(infile);
        }
    }
    return posts;
}

void writeToFile(ofstream &outfile, Post *post) {
    post->print(outfile);
}

Post *printVideoPosts(ifstream &infile, ofstream &outfile) {
    int n;
    Post **posts = readMultiplePosts(infile, &n);
    Post *mostPopularVideoPost = nullptr;

    for (int i = 0; i < n; i++) {
        VideoPost *videoPost = dynamic_cast<VideoPost *>(posts[i]);
        if (videoPost) {
            writeToFile(outfile, videoPost);
            outfile << endl;

            if (mostPopularVideoPost == nullptr || videoPost->popularity() > mostPopularVideoPost->popularity()) {
                mostPopularVideoPost = videoPost;
            }
        }
    }
    return mostPopularVideoPost;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output1.txt");

    int testCase;
    inFile >> testCase;
    inFile.ignore();

    if (testCase == 1) {
        Post *post = readPhotoPost(inFile);
        outFile << "Test PhotoPost" << endl;
        outFile << "Popularity: " << post->popularity() << endl;
        writeToFile(outFile, post);
    } else if (testCase == 2) {
        Post *post = readVideoPost(inFile);
        outFile << "Test VideoPost" << endl;
        outFile << "Popularity: " << post->popularity() << endl;
        writeToFile(outFile, post);
    } else if (testCase == 3) {
        int n;
        Post **posts = readMultiplePosts(inFile, &n);
        outFile << "Test operator >=" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*posts[i]) >= (*posts[j])) {
                        outFile << i << " >= " << j << endl;
                    } else {
                        outFile << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        Post **posts = readMultiplePosts(inFile, &n);
        for (int i = 0; i < n; i++) {
            writeToFile(outFile, posts[i]);
            outFile << endl;
        }
        outFile << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n)
                << endl;

        outFile << "The least popular twitter post is: " << endl;
        Post *result = leastPopularTwitterPost(posts, n);
        if (result == nullptr) {
            outFile << "None";
        } else {
            writeToFile(outFile, result);
        }
        outFile << printVideoPosts(inFile, outFile);
    }

    inFile.close();
    outFile.close();
}
