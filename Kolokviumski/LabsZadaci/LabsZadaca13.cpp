#include<iostream>
#include <vector>
#include<cstring>
#include <algorithm>


using namespace std;

class ShoppingList {
private:
    vector<string> shopListArticle;
    vector<string> restrictedItems;
public:
    ShoppingList(const vector<string> &restrictedItems) : restrictedItems(restrictedItems) {
    }

    ShoppingList &operator+=(const string &item) {
        for (int i = 0; i < restrictedItems.size(); ++i) {
            if (restrictedItems[i] == item) {
                return *this;
            }
        }
        shopListArticle.push_back(item);
        return *this;
    }

    ShoppingList &operator-=(const string &item) {
        for (int i = 0; i < shopListArticle.size(); ++i) {
            if (shopListArticle[i] == item) {
                shopListArticle.erase(shopListArticle.begin() + i);
                return *this;
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const ShoppingList &list) {
        for (size_t i = 0; i < list.shopListArticle.size(); ++i) {
            os << list.shopListArticle[i];
            if (i < list.shopListArticle.size() - 1) {
                os << ", ";
            }
        }
        return os;
    }

};


int main() {
    vector<string> restrictedItems;
    string restrictedItem;
    while (cin >> restrictedItem) {
        if (restrictedItem == "done") {
            break;
        }
        restrictedItems.push_back(restrictedItem);
    }
    ShoppingList list(restrictedItems);
    string item;
    while (cin >> item) {
        if (item == "exit") {
            break;
        }
        list += item;
    }
    cout << list << endl;
    cin >> item;
    list -= item;
    cout << list << endl;

    return 0;
}
