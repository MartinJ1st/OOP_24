#include <iostream>

using namespace std;

class BC {
public:
    BC() { cout << "BC::BC()" << endl;}

private:
    int x;
};

class DC : public BC {
public:
    DC() {
        cout <<"DC::DC()" << endl;
    }
private:
    int y;
};

int main() {
    DC d;
    return 0;
    
}