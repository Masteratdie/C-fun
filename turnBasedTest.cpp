#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Weapons {
	public:

		Weapons(string type) {
			if (type == "Broadsword") {
				damage = 3;
				weaponType = type;
			}
			if (type == "Poison Sword") {
				damage = 2;
				ailer = "poison";
				weaponType = type;
			}
		}

		int getDamage() {
			return damage;
		}

		string getAiler() {
			return ailer;
		}

		string getWeaponType() {
			return weaponType;
		}


	private:
		int damage;
		string weaponType;
		string ailer = "None";
};

class Enemy {
	public:
		Enemy(string type) {
			if (type == "Goomba") {
				hp = 5;
				damage = 1;
				xpWorth = 5;
				Enemytype = type;
				damageType = "Headbonk";
				speed = 1;
			}
			if (type == "Flying Goomba") {
				hp = 10;
				damage = 3;
				xpWorth = 15;
				Enemytype = type;
				damageType = "Flying Kick";
				speed = 5;
			}
		}

		int inflictDamage() {
			cout << "The " << Enemytype << " hits you with a " << damageType << " dealing " << damage << " damage to you" << "\n"<< endl;
			return damage;
		}

		void setStatus(string aStatus) {
			status = aStatus;
		}

		int getSpeed() {
			return speed;
		}

		void takeDamage(int wound) {
			hp -= wound;
			cout << "Debug Health: " << hp;
		}

		int getHp() {
			return hp;
		}

		string getEnemyType() {
			return Enemytype;
		}

		int getXpWorth() {
			return xpWorth;
		}

		void inflictStatus() {
			if (status == "poison") {
				damage -= 1;
			}
		}		

	private:
		int hp;
		string Enemytype;
		int damage;
		string damageType;
		int xpWorth;
		string status;
		int speed;

};


class Player {
	public:
		Player(string aName) {
			name = aName;
		}

		int inflictDamage(Weapons weapon, Enemy enemy) {
			damage = weapon.getDamage();
			enemy.setStatus(weapon.getAiler());

			if (weapon.getWeaponType() == "Broadsword") {
				cout << "You attack with your Broadsword, dealing " << weapon.getDamage() << " damage to the " << enemy.getEnemyType() << "\n"<< endl;
			}
			if (weapon.getWeaponType() == "Poison Sword") {
				cout << "You attack with your Poison Sword, dealing " << weapon.getDamage() << " damage to the " << enemy.getEnemyType() << "\n" << endl;
				cout << "The " << enemy.getEnemyType() << "is poisoned, dealing 1 extra damage";
			}
			return damage;
		}

		void takeDamage(int wound) {
			damage -= wound;
		}

		void addXp(int aXp) {
			xp += aXp;
		}

		int getXp() {
			return xp;
		}

		int getSpeed() {
			return speed;
		}

		int getHp() {
			return hp;
		}
	private:
		int hp = 1;
		int damage;
		int xp = 0;
		string name;
		int speed = 3;
};

void playerTurn(Player& player, Weapons& weapon, Enemy& enemy) {
	char userC;
	cout << "Would you like to attack with your " << weapon.getWeaponType() << "?(y/n)" << endl;
	cin >> userC;

	if (userC == 'y') {
		enemy.takeDamage(player.inflictDamage(weapon, enemy));
	}
}

void enemyTurn(Player& player, Enemy& enemy) {
	player.takeDamage(enemy.inflictDamage());
	enemy.inflictStatus();

}

void printStats(Player& player, Enemy& enemy) {
	cout << "You have " << player.getHp() << " health left" << endl;
	cout << "The " << enemy.getEnemyType() << " has " << enemy.getHp() << " health left" << endl;
}

void battle(Player& player, Weapons& weapon, Enemy& enemy) {
	int rounds = 1;
	bool pFirst = false;

	if (player.getSpeed() >= enemy.getSpeed()) {
		pFirst = true;
	}

	//cout << player.getHp();
	while (player.getHp() > 0 && enemy.getHp() > 0){
		cout << "\nRound: " << rounds << endl;

		if (pFirst == true) {
			playerTurn(player, weapon, enemy);
			enemyTurn(player, enemy);
		}
		else {
			enemyTurn(player, enemy);
			playerTurn(player, weapon, enemy);
		}

		cout << "Debug2: "<< enemy.getHp() << endl;
		cout << "After round " << rounds << ":" << endl;
		printStats(player, enemy);
		rounds++;
	}

	if (player.getHp() > 0) {
		cout << "You beat the " << enemy.getEnemyType() << "!" << endl;
		cout << "You gain " << enemy.getXpWorth() << " xp";
		player.addXp(enemy.getXpWorth()); 
	}
	else {
		cout << "You have been defeated by the mighty " << enemy.getEnemyType() << endl;
		cout << "Game Over!" << endl;
	}

}


int main() {
	string userS;

	cout << "What's your name? " << endl;
	cin >> userS;

	Player player(userS);

	cout << "Would you like a Broadsword or a Poison Sword?(Enter b or p) " << endl;

	cin >> userS;

	if (userS == "b") {
		userS = "Broadsword";
	}
	else {
		userS = "Poison Sword";
	}

	Weapons playerWeapon(userS);

	//simulate battle time
	Enemy goomba("Goomba");

	battle(player, playerWeapon, goomba);
	cin >> userS;
}