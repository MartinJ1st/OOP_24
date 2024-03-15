#include <iostream>

using namespace std;

struct InvoiceItem {
    char id[11];
    int quantity;
    int price;
};

struct Invoice {
    char id[11];
    int numItems;
    InvoiceItem items[100];
};

struct Client {
    char name[100];
    int numInvoices;
    Invoice invoices[100];
};

void bestClient(Client *clients, int numClients) {
    double max = 0;
    int index = -1;

    for (int i = 0; i < numClients; ++i) {
        double sum = 0;
        for (int j = 0; j < clients[i].numInvoices; ++j) {
            for (int k = 0; k < clients[i].invoices[j].numItems; ++k) {
                sum += clients[i].invoices[j].items[k].quantity * clients[i].invoices[j].items[k].price;
            }
            sum *= 1.18;
        }

        if (sum > max) {
            max = sum;
            index = i;
        }
    }
    cout << clients[index].name << endl;
}

int main() {
    int n;
    cin >> n;

    Client clients[n];

    for (int i = 0; i < n; ++i) {
        cin >> clients[i].name >> clients[i].numInvoices;

        for (int j = 0; j < clients[i].numInvoices; ++j) {
            cin >> clients[i].invoices[j].id >> clients[i].invoices[j].numItems;

            for (int k = 0; k < clients[i].invoices[j].numItems; ++k) {
                cin >> clients[i].invoices[j].items[k].id >> clients[i].invoices[j].items[k].quantity
                    >> clients[i].invoices[j].items[k].price;
            }
        }
    }

    bestClient(clients, n);

    return 0;
}
