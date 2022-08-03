#pragma once
#include <iostream>
#include <string>
#include <limits>

template<typename T>
void getInput(T& input, const std::string msg) {
	std::cout << msg;
	std::cin >> input;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "INPUT ERROR! Please enter correct type\n";

		std::cout << msg;
		std::cin >> input;
	}
}