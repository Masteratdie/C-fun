#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

using namespace std;

class Card {
public:
    Card() {

    }

    Card(string cardSuit, int cardValue) {
        this-> cardSuit = cardSuit;
        this-> cardValue = cardValue;
    }

    void print() {
        cout << cardSuit << ", ";
        switch (cardValue) {
        case 11:
            cout << "Jack" << endl;
            break;
        case 12:
            cout << "Queen" << endl;
            break;
        case 13:
            cout << "King" << endl;;
            break;
        case 14:
            cout << "Ace" << endl;
            break;
        default:
            cout << cardValue << endl;
        }
    }

    void setCard(string suit, int value) {
        cardSuit = suit;
        cardValue = value;
    }

    void setSuit(string suit) {
        cardSuit = suit;
    }

    string getSuit() {
        return cardSuit;
    }

    void setValue(int value) {
        cardValue = value;
    }

    int getValue() {
        return cardValue;
    }

    void setSpecialValue(int value) {
        cardSpecialValue = value;
    }

    int getSpecialValue() {
        return cardSpecialValue;
    }

private:
    string cardSuit;
    int cardValue;
    int cardSpecialValue = 0;
};

class Deck {
public:

    Deck() {

    }

    int size() {
        return cards.size();
    }

    void create() {
        cards.resize(52);
        int cardNum = 0;

        for (int value = 2; value <= 14; value++) {
            cards[cardNum].setCard(CLUB, value);
            cardNum++;
            if (value > 9 and value < 14) {
                cards[cardNum].setSpecialValue(10);
            }
            else if (value == 14) {
                cards[cardNum].setSpecialValue(11);
            }

            cards[cardNum].setCard(SPADE, value);
            cardNum++;
            if (value > 9 and value < 14) {
                cards[cardNum].setSpecialValue(10);
            }
            else if (value == 14) {
                cards[cardNum].setSpecialValue(11);
            }

            cards[cardNum].setCard(HEART, value);
            cardNum++;
            if (value > 9 and value < 14) {
                cards[cardNum].setSpecialValue(10);
            }
            else if (value == 14) {
                cards[cardNum].setSpecialValue(11);
            }

            cards[cardNum].setCard(DIAMOND, value);
            cardNum++;
            if (value > 9 and value < 14) {
                cards[cardNum].setSpecialValue(10);
            }
            else if (value == 14) {
                cards[cardNum - 1].setSpecialValue(11);
            }
        }
    }

    void shuffle() {
        vector<int> randIndex;
        int random;
        srand(time(NULL));
        int key;

        while (randIndex.size() != cards.size()) {
            random = rand() % cards.size();
            key = random;

            if (find(randIndex.begin(), randIndex.end(), key) != randIndex.end()) {

            }
            else {
                randIndex.push_back(random);
            }

        }

        vector<Card> tmp;
        tmp.resize(cards.size());

        for (int i = 0; i <= tmp.size() - 1; i++)
            tmp[i] = cards[randIndex[i]];

        cards = tmp;
    }

    void print() {
        for (int i = 0; i <= cards.size() - 1; i++) {
            cout << setw(7) << cards[i].getSuit() << ": ";

            switch (cards[i].getValue()) {
            case 11:
                cout << "Jack" << endl;
                break;
            case 12:
                cout << "Queen" << endl;
                break;
            case 13:
                cout << "King" << endl;;
                break;
            case 14:
                cout << "Ace" << endl;
                break;
            default:
                cout << cards[i].getValue() << endl;
            }
        }
    }

    void dropCard() {
        //removes 1 card
        cards.erase(cards.begin());

        //removes 3
        //cards.erase(cards.begin(), cards.begin()+3);
    }

    Card getTopCard() {
        Card firstCard = cards[0];

        return firstCard;
    }

    friend class Person;
private:
    vector<Card> cards;
    const string CLUB = "CLUB";
    const string SPADE = "SPADE";
    const string HEART = "HEART";
    const string DIAMOND = "DIAMOND";
};

class Person {

public:

    Card getNewestCard() {
        return hand[hand.size() - 1];
    }

    void resetHand() {
        hand.clear();
    }

    void personDraw(Deck cards) {
        hand.push_back(cards.getTopCard());
    }

    void print(bool hidden = false) {
        if (hidden == false) {
            for (int i = 0; i <= hand.size() - 1; i++) {
                //cout << "DEBUG VALUE: " << hand[i].getValue() << endl;
                //cout << "DEBUG SPECIAL VALUE: " << hand[i].getSpecialValue() << endl;
                cout << hand[i].getSuit() << ", ";

                switch (hand[i].getValue()) {
                case 11:
                    cout << "JACK" << endl;
                    break;
                case 12:
                    cout << "QUEEN" << endl;
                    break;
                case 13:
                    cout << "KING" << endl;
                    break;
                case 14:
                    cout << "ACE" << endl;
                    break;
                default:
                    cout << hand[i].getValue() << endl;
                }
            }
            cout << endl;
        }
        else {
            cout << hand[0].getSuit() << ", ";
            switch (hand[0].getValue()) {
            case 11:
                cout << "JACK" << endl;
                break;
            case 12:
                cout << "QUEEN" << endl;
                break;
            case 13:
                cout << "KING" << endl;
                break;
            case 14:
                cout << "ACE" << endl;
                break;
            default:
                cout << hand[0].getValue() << endl;
            }
            cout << "FACE DOWN" << endl;
        }
    }

    int handValue() {
        int total = 0;

        for (int i = 0; i <= hand.size() - 1; i++) {
            if (hand[i].getSpecialValue() == 0) {
                total += hand[i].getValue();
            }
            else if (hand[i].getSpecialValue() > 0) {
                total += hand[i].getSpecialValue();
            }
        }

        return total;
    }

    void playerAceCheck(bool start = false) {
        char user;

        if (start == true) {
            for (int i = 0; i <= hand.size() - 1; i++) {

                if (hand[i].getSpecialValue() == 11) {
                    cout << "Would you like to make your ACE 1?(y/n)" << endl;
                    cin >> user;

                    if (user == 'y' or user == 'Y') {
                        hand[i].setSpecialValue(1);
                    }
                }
            }
        }

        else {
            if (hand[hand.size() - 1].getSpecialValue() == 11) {
                cout << "Would you like to make your ACE 1?(y/n)" << endl;
                cin >> user;

                if (user == 'y' or user == 'Y') {
                    hand[hand.size() - 1].setSpecialValue(1);
                }
            }
        }
    }

    int getMoney() {
        return money;
    }

    void setMoney(int money) {
        this->money = money;
    }

    int getWager() {
        return wager;
    }

    void setWager(int wagerAmount) {
        wager = wagerAmount;
    }

    bool getStand() {
        return stand;
    }

    void setStand(bool stand) {
        this->stand = stand;
    }

private:
    vector<Card> hand;
    int money;
    int wager;
    bool stand = false;
};

void dealerCheck(Person& dealer, int& dealerAces) {
    if (dealer.getNewestCard().getValue() == 14 && dealerAces < 1 && dealer.handValue() > 21) {
        dealer.getNewestCard().setSpecialValue(1);
        dealerAces += 1;
    }

    else if (dealerAces > 0) {
        dealer.getNewestCard().setSpecialValue(1);
    }
}

char dealerTurn(Person& dealer) {
    if (dealer.handValue() < 17) {
        return 'h';
    }

    else {
        return 's';
    }
}

void gameStart(Deck& deck, Person& player, Person& dealer, int& dealerAces) {
    int wager;
    cout << "You have $" << player.getMoney() << endl;
    cout << "How much would you like to wager? ";
    cin >> wager;

    //debugging
    //wager = 1;

    if (wager < 1) {
        cout << "Wager too small! Setting wager to 1" << endl;
        player.setWager(1);
    }

    else if (wager > player.getMoney()) {
        cout << "Wager too large! Setting wager to total money" << endl;
        player.setWager(player.getMoney());
    }

    else {
        player.setWager(wager);
    }

    bool hidden = true;
    bool start = true;

    for (int i = 0; i < 2; i++) {
        player.personDraw(deck);
        deck.dropCard();

        dealer.personDraw(deck);

        //cout << "Dealer Before: " << endl;
        //cout << dealer.handValue() << endl;

        deck.dropCard();
        dealerCheck(dealer, dealerAces);

        //cout << "Dealer After: " << endl;
        //cout << dealer.handValue() << endl;

    }

    cout << "Your Hand(" << player.handValue() << "): " << endl;
    player.print();

    cout << "Dealers Hand: " << endl;
    dealer.print(hidden);

    player.playerAceCheck(start);

}

void blackJack(Deck& deck, Person& player, Person& dealer, bool& quit) {
    int dealerAcesCount = 0;
    gameStart(deck, player, dealer, dealerAcesCount);

    char user;

    bool end = false;
    bool start = true;
    while (player.handValue() < 21 and dealer.handValue() < 21 and end == false) {

        //Player's turn
        if (player.getStand() == false && dealer.handValue() < 21) {
            if (start == false) {
                cout << "Your Turn " << endl << endl;
                
                cout << "Your Hand(" << player.handValue() << "): " << endl;
                player.print();

            }
            start = false;
            cout << "Would you like to stand or hit?(s/h)" << endl;
            cin >> user;

            //debugging
            //user = 'h';

            if (user == 'h' or user == 'H') {
                player.personDraw(deck);
                deck.dropCard();

                cout << "You draw ";
                player.getNewestCard().print();
                cout << endl;
                player.playerAceCheck();
            }
            else {
                player.setStand(true);
            }
        }

        //Dealer's turn
        if (dealer.getStand() != true && player.handValue() < 21) {
            cout << "Dealer's Turn " << endl;
            if (dealerTurn(dealer) == 'h') {
                dealer.personDraw(deck);
                deck.dropCard();
                dealerCheck(dealer, dealerAcesCount);

                cout << "The dealer hits" << endl << endl;
            }
            else {
                dealer.setStand(true);
                cout << "The dealer stands" << endl << endl;
            }

            cout << "Dealers Hand(" << dealer.handValue() << "): " << endl;
            dealer.print();
            Sleep(2 * 1000);
        }

        if (player.getStand() == true && dealer.getStand() == true) {
            end = true;
        }
    }

    player.setStand(false);
    dealer.setStand(false);

    int winnings = player.getWager() * 2;
    int losing = player.getWager();


    if (player.handValue() == dealer.handValue()) {
        cout << "You and the dealer tied! You neither gain nor lose money" << endl;
    }

    else if (player.handValue() > 21 && dealer.handValue() > 21) {
        cout << "You both bust, house wins! You lost $" << winnings << endl;
        player.setMoney(player.getMoney() - losing);

    }

    else if (player.handValue() > dealer.handValue() && player.handValue() <= 21 || dealer.handValue() > 21) {
        if (dealer.handValue() > 21) {
            cout << "The dealers's hand busts!" << endl << endl;
        }
        //cout << "DEBUG: YHAND: " << player.handValue() << " DHAND: " << dealer.handValue() << endl;
        cout << "Congratulations! You beat the house and win $" << winnings << endl;
        player.setMoney(player.getMoney() + winnings);
    }

    else if (player.handValue() < dealer.handValue() && dealer.handValue() <= 21 || player.handValue() > 21) {
        if (player.handValue() > 21) {
            cout << "Your hand busts!" << endl << endl;
        }
        //cout << "DEBUG: YHAND: " << player.handValue() << " DHAND: " << dealer.handValue() << endl;
        cout << "The house wins! You lose $" << losing << endl;
        player.setMoney(player.getMoney() - losing);
    }

    else {
        cout << "OUTCOME NOT ACCOUTNED FOR" << endl;
        cout << "DEBUG: YHAND: " << player.handValue() << " DHAND: " << dealer.handValue() << endl;
    }

    cout << "Would you like to play another round?(y/n)";
    cin >> user;

    if (user == 'n' || user == 'N') {
        quit = true;
    }
    cout << endl;
}

void repeatGame(Deck& deck, Person& player, Person& dealer, bool& quit) {
    const int STARTING_MONEY = player.getMoney();
    while (player.getMoney() > 0 && quit != true) {
        if (deck.size() < 6) {
            deck.create();
            deck.shuffle();
        }
        player.resetHand();
        dealer.resetHand();
        blackJack(deck, player, dealer, quit);
    }

    if (player.getMoney() < 1) {
        cout << "You gambled away all your money.\n" << "\nYour wife would come to murder you that night.\nAnd as she stabbed you to death she just kept screaming \"SILLY RABBIT, TRICKS ARE FOR KIDS!\"" << endl;
    }

    else if (player.getMoney() > STARTING_MONEY) {
        cout << "Congratulations! You made $" << player.getMoney() - STARTING_MONEY << endl;
    }

    else {
        cout << "You lost $" << STARTING_MONEY - player.getMoney() << ", but at least you live to gamble another day" << endl;
    }
};

int main() {
    Deck deck;
    deck.create();
    deck.shuffle();

    Person dealer;
    Person player;
    player.setMoney(500);

    cout << "Welcome to Blackjack" << endl << endl;

    bool quit = false;
    repeatGame(deck, player, dealer, quit);

    cout << "\nEnter anything to quit: " << endl;
    int terminalOpen;
    cin >> terminalOpen;
}