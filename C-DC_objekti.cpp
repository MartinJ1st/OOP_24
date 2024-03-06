#include <iostream>
#include <cstring>

using namespace std;

class Test {
public:
// konstruktor so eden argument
    Test(const char *name);

    ~Test() { cout << "Unisten Test objekt " << ime << endl; }

private:
    char ime[20];
};

Test::Test(const char *name) {
    cout << "Kreiran Test objekt "
         << name << endl;
    strncpy(ime, name, 19);
    ime[19] = 0;
}

Test globaltest("global");

void func() {
    static Test statictest("static");
    Test functest("func");
}

int main() {
    Test first("main first");
    func();
    {
        Test first("main inner");
    }
    Test second("main second");
}