#include <cstring>
#include <iostream>
using namespace std;

enum Size{small, large, family};

// Your Code goes here
class Pizza{
protected:
    char name[20];
    char ingredients[100];
    float basePrice;
public:
    Pizza(char *name="", char *ingredients= nullptr, float basePrice=0){
        strcpy(this->name,name);
        strcpy(this->ingredients,ingredients);
        this->basePrice = basePrice;
    }

    virtual float price()=0;
    virtual ostream &print(ostream &out)=0;

    bool operator<(Pizza &p){
        return price()<p.price();
    }

    friend ostream &operator<<(ostream &out, Pizza &p){
        p.print(out);
        return out;
    }
};

class FlatPizza: public Pizza{
private:
    Size pizzaSize;
public:
    FlatPizza(char *name="", char *ingredients=0, float basePrice=0, Size pizzaSize=(Size)0): Pizza(name,ingredients,basePrice){
        this->pizzaSize=pizzaSize;
    }

    float price(){
        if(pizzaSize == small){
            return basePrice*1.1;
        }
        if(pizzaSize == large){
            return basePrice*1.2;
        }
        if(pizzaSize == family){
            return basePrice*1.3;
        }
    }

    ostream &print(ostream &out){
        out<<name<<": "<<ingredients<<", ";
        if(pizzaSize == small){
            out<<"small";
        }
        if(pizzaSize == large){
            out<<"large";
        }
        if(pizzaSize == family){
            out<<"family";
        }
        out<<" - "<<price()<<endl;
        return out;
    }
};

class FoldedPizza: public Pizza{
private:
    bool whiteFlour;
public:
    FoldedPizza(char *name="", char *ingredients=0, float basePrice=0, bool whiteFlour=true): Pizza(name,ingredients,basePrice){
        this->whiteFlour=whiteFlour;
    }

    float price(){
        if(whiteFlour){
            return basePrice*1.1;
        }

        return basePrice*1.3;
    }

    void setWhiteFlour(bool whiteFlour){
        this->whiteFlour=whiteFlour;
    }

    ostream &print(ostream &out){
        out<<name<<": "<<ingredients<<", ";
        if(whiteFlour){
            cout<<"wf";
        } else{
            cout<<"nwf";
        }
        out<<" - "<<price()<<endl;

        return out;
    }
};

void expensivePizza(Pizza *p[], int numPizza){
    int max_indeks=0;
    for(int i=0;i<numPizza;i++){
        if(*p[max_indeks]< *p[i]){
            max_indeks=i;
        }
    }

    cout<<*p[max_indeks]<<endl;
}
// Testing

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(name, ingredients, inPrice, (Size)s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp1;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp2;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout<<"Lower price: "<<endl;
        if(*fp1<*fp2)
            cout<<fp1->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp1<*fp3)
            cout<<fp1->price()<<endl;
        else cout<<fp3->price()<<endl;

        if(*fp4<*fp2)
            cout<<fp4->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp3<*fp4)
            cout<<fp3->price()<<endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}
