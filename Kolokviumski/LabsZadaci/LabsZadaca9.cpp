#include <iostream>
#include <string>

using namespace std;

class InvalidIPAddressException {
public:
    void what() {
        cout << "IP address invalid." << endl;
    }
};

class InvalidPortException {
private:
    int port;
public:
    InvalidPortException(int port) : port(port) {}

    void what() {
        cout << "Port number " << port << " is invalid." << endl;
    }
};

class NetworkDevice {
protected:
    string brand;
    string model;
public:
    NetworkDevice(const string &brand = "", const string &model = "") : brand(brand), model(model) {}

    void print() const {
        cout << brand << " " << model << endl;
    }
};

class NetworkInterface {
protected:
    int ipAddress[4];
    int ports[5];
public:
    NetworkInterface(int *ipAddress, int *ports) {
        for (int i = 0; i < 4; ++i) {
            if (ipAddress[i] < 1 || ipAddress[i] > 254) {
                throw InvalidIPAddressException();
            }
            this->ipAddress[i] = ipAddress[i];
        }

        for (int i = 0; i < 5; ++i) {
            if (ports[i] < 0 || ports[i] > 65535) {
                throw InvalidPortException(ports[i]);
            }
            this->ports[i] = ports[i];
        }
    }


    void print() const {
        cout << "IP octets: ";
        for (int i = 0; i < 4; ++i) {
            cout << ipAddress[i] << " ";
        }
        cout << endl;

        cout << "Allowed ports: ";
        for (int i = 0; i < 5; ++i) {
            cout << ports[i] << " ";
        }
        cout << endl;
    }
};

class Host : public NetworkDevice, public NetworkInterface {
public:
    Host(string brand, string model, int ipAddress[4], int ports[5]) : NetworkDevice(brand, model),
                                                                       NetworkInterface(ipAddress, ports) {
    }

    void print() const {
        cout << "Host:" << endl;
        NetworkDevice::print();
        NetworkInterface::print();
    }
};

class Firewall : public NetworkDevice, public NetworkInterface {
public:
    Firewall(string brand, string model, int ipAddress[4], int ports[5]) : NetworkDevice(brand, model),
                                                                           NetworkInterface(ipAddress, ports) {
    }

    void print() const {
        cout << "Firewall:" << endl;
        NetworkDevice::print();
        NetworkInterface::print();
    }
};


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string brand, model;
        cin >> brand >> model;
        int ipAddress[4];
        for (int j = 0; j < 4; ++j) {
            cin >> ipAddress[j];
            cin.ignore(1);
        }
        int ports[5];
        for (int j = 0; j < 5; ++j) {
            cin >> ports[j];
        }
        try {


            if (i % 2 == 0) {
                Host h(brand, model, ipAddress, ports);
                h.print();
            } else {
                Firewall f(brand, model, ipAddress, ports);
                f.print();
            }
        } catch (InvalidIPAddressException e) {
            e.what();
        } catch (InvalidPortException e) {
            e.what();
        }
    }
    return 0;
}
