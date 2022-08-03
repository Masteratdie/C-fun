#include <SFML/Graphics.hpp>
#include "Collider.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paint", sf::Style::Close);

	//sf::RectangleShape player(sf::Vector2f(20.0f, 20.0f));
	//sf::CircleShape player(25.0);

	float size = 20.0f;
	sf::RectangleShape player(sf::Vector2f(size, size));
	player.setFillColor(sf::Color::White);
	int randR; int randG; int randB;

	bool first = true;
	sf::Event evnt;
	while (window.isOpen()) {

		while (window.pollEvent(evnt)) {
			//if (eaten == true) {
				//eaten = false;
			//}
			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		//apple.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			window.clear(player.getFillColor());
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
			window.draw(player);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			size = 5.0f;
			player.setSize(sf::Vector2f(size, size));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			size = 10.0f;
			player.setSize(sf::Vector2f(size, size));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			size = 20.0;
			player.setSize(sf::Vector2f(size, size));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			size = 50.0f;
			player.setSize(sf::Vector2f(size, size));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Dash)) {
			player.setFillColor(sf::Color::White);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal)) {
			player.setFillColor(sf::Color::Black);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
			randR = rand() % 255;
			randG = rand() % 255;
			randB = rand() % 255;

			player.setFillColor(sf::Color(randR, randG, randB));
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
			player.setFillColor(sf::Color::Red);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
			player.setFillColor(sf::Color::Green);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
			player.setFillColor(sf::Color::Blue);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
			player.setFillColor(sf::Color::Magenta);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
			player.setFillColor(sf::Color::Yellow);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) {
			player.setFillColor(sf::Color(255,165,0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)) {
			player.setFillColor(sf::Color(55, 197, 213));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8)) {
			player.setFillColor(sf::Color(31, 236, 175));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9)) {
			player.setFillColor(sf::Color(168, 31, 236));
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0)) {
			player.setFillColor(sf::Color(128, 128, 128));
		}
		//window.clear(sf::Color::White);
		//window.draw(apple);
		window.display();
	}
	return 0;
}