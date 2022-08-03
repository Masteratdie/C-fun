#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sword {
    public:
        Sword() {

        }

        int attack(string attack) {
            if (attack == "swing") {
                cout << "You swing and do " << swing << " damage\n" << endl; 
                return swing;
            }
            if (attack == "stab") {
                cout << "You stab and do " << swing << " damage\n" << endl;
                return stab;
            }
            return 1;
        }


    private:
        int swing = 7;
        int stab = 4;

};

class Enemy {
    public:
        Enemy(int aHp) {
            hp = aHp;
        }

        void hurt(int damage) {
            hp -= damage;
            if (hp < 0) {
                hp = 0;
            }
        }

        int getHp() {
            return hp;
        }

        int doDamage() {
            cout << "You take " << damage << " bite damage\n" << endl;
            return damage;
        }


    private:
        int hp;
        int damage = 5;
};

class Player {
    public:
        Player(int aHp) {
            hp = aHp;
        }

        int getHp() {
            return hp;
        }

        void hurt(int damage) {
            hp -= damage;
            if (hp < 0) {
                hp = 0;
            }

        }


    private:
        int hp;
};


void status(Player person, Enemy badguy) {
    cout << setw(10) << "Player health: " << person.getHp() << endl;
    cout << setw(10) << "Enemy health: " << badguy.getHp() << endl;
}

void Battle() {
    Enemy goomba(20);
    Player aaron(20);
    Sword falchion;
    string user;

    while (aaron.getHp() > 0 && goomba.getHp() > 0) {
        cout << "Choose either swing or stab attacks" << endl;
        cin >> user;

        goomba.hurt(falchion.attack(user));
        status(aaron, goomba);

        aaron.hurt(goomba.doDamage());
        status(aaron, goomba);

    }
    if (aaron.getHp() > 0){
        cout << "Congrats! You beat the enemy";
    }
    else {
        cout << "Game Over!";
    }
    cin >> user;




}


int main() {
    Battle();
}


//     public:
//         Book();
//         ~Book();
//     private:
//         string title(string title = "Not Found!") {

//         }

//         string author(string author = "Not Found!") {

//         }

//         int pages(pages = 0) {

//         }

//         int date(date = 0) {

//         }
// };