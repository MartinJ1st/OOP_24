#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class ExistingGame{
public:
    void message(){
        cout<<"The game is already in the collection"<<endl;
    }
};

class Game{
protected:
    char name[100];
    float price;
    bool discounted;
public:
    Game(char *name="", float price=0, bool discounted=false){
        strcpy(this->name,name);
        this->price=price;
        this->discounted=discounted;
    }

    const char *getName() const {
        return name;
    }

    virtual float cost(){
        if(discounted){
            return price * 0.7;
        }
        return price;
    }

    virtual ostream &print(ostream &out){
        //Game: World of Warcraft, regular price: $40, monthly fee: $10, purchased: 1-2017
        out<<"Game: "<<name<<", regular price: $"<<price;
        if(discounted){
            out<<", bought on sale";
        }
        return out;
    };

    virtual istream &input(istream &in){
        in.get();
        in.getline(name,100);
        in>>price>>discounted;
        return in;
    }

    friend istream &operator>>(istream &in, Game &g){
        return g.input(in);
    }

    friend ostream &operator<<(ostream &out, Game &g){
        return g.print(out);
    }
};

class SubscriptionGame : public Game{
private:
    float monthlyPayment;
    int month;
    int year;
public:
    SubscriptionGame(char *name="", float price=0, bool discounted=false, float monthlyPayment=0, int month=0, int year=0) : Game(name,price, discounted){
        this->monthlyPayment=monthlyPayment;
        this->month=month;
        this->year=year;
    }

    float cost(){
        if(year==2018 && month<5){
            return Game::cost()+(5-month)*monthlyPayment;
        }
        return Game::cost() + ((2018-(year+1))*12+(12-month+5))*monthlyPayment;
    }

    ostream &print(ostream &out){
        Game::print(out)<<", monthly fee: $"<<monthlyPayment<<", purchased: "<<month<<"-"<<year;
        return out;
    }

    istream &input(istream &in){
        Game::input(in);
        in>>monthlyPayment>>month>>year;
        return in;
    }
};

class User{
private:
    char name[100];
    Game **games;
    int n;
public:
    User(char *name=0){
        strcpy(this->name,name);
        n=0;
        games = new Game* [n];
        games[n] = new Game();
    }

    User(const User &u){
        strcpy(this->name,u.name);
        n=u.n;
        games = new Game* [n];
        for(int i=0;i<n;i++){
            SubscriptionGame *sg = dynamic_cast<SubscriptionGame*>(games[i]);
            if(sg != nullptr){
                games[i] = new SubscriptionGame(*sg);
                continue;
            }
            games[i] = new Game(*u.games[i]);
        }
    }

    ~User(){
        for(int i=0;i<n;i++){
            delete games[i];
        }
        delete [] games;
    }


    User &operator+=(Game &g){
        for(int i=0;i<n;i++){
            if(strcmp(games[i]->getName(), g.getName())==0){
                throw ExistingGame();
            }
        }

        Game **tmp = new Game * [n+1];
        for(int i=0;i<n;i++){
            SubscriptionGame *sg = dynamic_cast<SubscriptionGame*>(games[i]);
            if(sg != nullptr){
                tmp[i] = new SubscriptionGame(*sg);
            } else{
                tmp[i] = new Game(*games[i]);
            }

        }

        SubscriptionGame *sg = dynamic_cast<SubscriptionGame*>(&g);
        if(sg != nullptr){
            tmp[n] = new SubscriptionGame(*sg);
        } else{
            tmp[n] = new Game(g);
        }
        n++;


        for(int i=0;i<n;i++){
            delete games[i];
        }
        delete [] games;


        games = tmp;
        return *this;
    }

    float total_spent(){
        float totalSpent=0;
        for(int i=0;i<n;i++){
            totalSpent +=games[i]->cost();
        }

        return totalSpent;
    }

    friend ostream &operator<<(ostream &out, User &u){
        out<<endl<<"User: "<<u.name<<endl;
        for(int i=0;i<u.n;i++){
            out<<"- "<<*u.games[i]<<endl;
        }
        out<<endl;
        return out;
    }
};
int main() {
    int test_case_num;

    cin>>test_case_num;

    // for Game
    char game_name[100];
    float game_price;
    bool game_on_sale;

    // for SubscritionGame
    float sub_game_monthly_fee;
    int sub_game_month, sub_game_year;

    // for User
    char username[100];
    int num_user_games;

    if (test_case_num == 1){
        cout<<"Testing class Game and operator<< for Game"<<std::endl;
        cin.get();
        cin.getline(game_name,100);
        //cin.get();
        cin>>game_price>>game_on_sale;

        Game g(game_name, game_price, game_on_sale);

        cout<<g;
    }
    else if (test_case_num == 2){
        cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
        cin.get();
        cin.getline(game_name, 100);

        cin>>game_price>>game_on_sale;

        cin>>sub_game_monthly_fee;
        cin>>sub_game_month>>sub_game_year;

        SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        cout<<sg;
    }
    else if (test_case_num == 3){
        cout<<"Testing operator>> for Game"<<std::endl;
        Game g;

        cin>>g;

        cout<<g;
    }
    else if (test_case_num == 4){
        cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
        SubscriptionGame sg;

        cin>>sg;

        cout<<sg;
    }
    else if (test_case_num == 5){
        cout<<"Testing class User and operator+= for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        try {

            for (int i=0; i<num_user_games; ++i){

                cin >> game_type;

                Game *g;
                // 1 - Game, 2 - SubscriptionGame
                if (game_type == 1){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;
                    g = new Game(game_name, game_price, game_on_sale);
                }
                else if (game_type == 2){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;

                    cin>>sub_game_monthly_fee;
                    cin>>sub_game_month>>sub_game_year;
                    g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
                }

                //cout<<(*g);


                u+=(*g);
            }
        }catch(ExistingGame &ex){
            ex.message();
        }

        cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

    }
    else if (test_case_num == 6){
        cout<<"Testing exception ExistingGame for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);

            try {
                u+=(*g);
            }
            catch(ExistingGame &ex){
                ex.message();
            }
        }

        cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
    }
    else if (test_case_num == 7){
        cout<<"Testing total_spent method() for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);


            u+=(*g);
        }

        cout<<u;

        cout<<"Total money spent: $"<<u.total_spent()<<endl;
    }
}
