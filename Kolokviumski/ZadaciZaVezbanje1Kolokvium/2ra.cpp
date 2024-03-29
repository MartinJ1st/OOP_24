#include <iostream>

using namespace std;

class List {
private:
    int *niza;
    int n;
public:
    List() {
        n = 0;
        niza = new int[0];
    }

    List(int *niza, int n) {
        this->n = n;
        this->niza = new int[n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = niza[i];
        }
    }

    List(const List &l) {
        n = l.n;
        niza = new int[n];
        for (int i = 0; i < n; i++) {
            niza[i] = l.niza[i];
        }
    }

    ~List() {
        delete[] niza;
    }

    List &operator=(const List &l) {
        if (this != &l) {
            delete[] niza;
            n = l.n;
            niza = new int[n];
            for (int i = 0; i < n; i++) {
                niza[i] = l.niza[i];
            }
        }
        return *this;
    }

    void pecati() {
        for (int i = 0; i < n; i++) {
            cout << i << ": " << niza[i] << " ";
        }
        cout << "sum: " << sum() << " average: " << average();
        cout << endl;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += niza[i];
        }
        return sum;
    }

    double average() {
        return (double) sum() / n;
    }
};

class ListContainer {
private:
    List *niza;
    int n;
    int tries;
public:
    ListContainer() {
        niza = new List[0];
        n = 0;
        tries = 0;
    }

    ListContainer(const ListContainer &lc) {
        n = lc.n;
        niza = new List[n];
        for (int i = 0; i < n; i++) {
            niza[i] = lc.niza[i];
        }
        tries = lc.tries;
    }

    ~ListContainer() {
        delete[] niza;
    }

    ListContainer operator=(const ListContainer &lc) {
        if (this != &lc) {
            delete[] niza;
            n = lc.n;
            niza = new List[n];
            for (int i = 0; i < n; i++) {
                niza[i] = lc.niza[i];
            }
            tries = lc.tries;
        }
        return *this;
    }

    void print() {
        if (tries == 0) {
            for (int i = 0; i < n; i++) {
                cout << "List number: " << i << " List info:";
                niza[i].pecati();
            }
        } else cout << "The list is empty" << endl;
    }

    void addNewList(List l) {
        List *tmp = new List[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = niza[i];
        }
        tmp[n++] = l;
        delete[] niza;
        niza = tmp;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += niza[i].sum();
        }
        return sum;

    }

    double average() {
        return (double) sum() / n;
    }
};

int main() {

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    } else {
        lc.print();
    }
}