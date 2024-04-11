#include <iostream>

using namespace std;

class List {
private:
    int *niza;
    int n;

    void copy(const List &l) {
        this->n = l.n;
        this->niza = new int[n];
        for (int i = 0; i < n; i++) {
            this->niza[i] = l.niza[i];
        }
    }

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
        copy(l);
    }

    ~List() {
        delete[] niza;
    }

    List &operator=(const List &l) {
        if (this != &l) {
            delete[] niza;
            copy(l);
        }
        return *this;
    }

    void print() {
        cout << n << ": ";
        for (int i = 0; i < n; i++) {
            cout << niza[i] << " ";
        }
        cout << "sum: " << sum() << " average: " << average() << endl;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += niza[i];
        }
        return sum;
    }

    double average() {
        return (double) sum() / (n * 1.0);
    }

    int getN() {
        return n;
    }

};

class ListContainer {
private:
    List *lists;
    int n;
    int tries;

    void copy(const ListContainer &lc) {
        this->n = lc.n;
        this->lists = new List[n];
        for (int i = 0; i < n; i++) {
            this->lists[i] = lc.lists[i];
        }
        this->tries = lc.tries;
    }

public:
    ListContainer() {
        n = 0;
        lists = new List[0];
        tries = 0;
    }

    ListContainer(const ListContainer &lc) {
        copy(lc);
    }

    ~ListContainer() {
        delete[] lists;
    }

    ListContainer &operator=(const ListContainer &lc) {
        if (this != &lc) {
            delete[] lists;
            copy(lc);
        }
        return *this;
    }

    void addNewList(List &l) {
        tries++;
        bool alreadyExists = false;
        for (int i = 0; i < n; i++) {
            if (lists[i].sum() == l.sum()) {
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) {
            List *tmp = new List[n + 1];
            for (int i = 0; i < n; i++) {
                tmp[i] = lists[i];
            }
            tmp[n++] = l;
            delete[] lists;
            lists = tmp;
        }
    }

    void print() {
        if (n == 0) {
            cout << "The list is empty" << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            cout << "List number: " << i + 1 << " List info: ";
            lists[i].print();
        }
        cout << "Sum: " << sum() << " Average: " << average() << endl;
        cout << "Successful attempts: " << n << " Failed attempts: " << abs(n-tries) << endl;
    }

    int sum() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += lists[i].sum();
        }
        return sum;
    }

    double average() {
        double sum = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            sum += lists[i].sum();
            num += lists[i].getN();
        }
        return sum / num;
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
