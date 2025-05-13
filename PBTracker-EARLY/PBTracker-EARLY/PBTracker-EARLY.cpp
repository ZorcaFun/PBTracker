#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

struct Transaction {
	std::string date;
	std::string type; // "Income" or "Expense"
	std::string category; // "Food" or "Salary"
	double amount;
	std::string decription;

	/*
	Structure Transaction take date, type, category, description string and amount as a double input and stock it here

	@param data is an string
	@param type is an string
	@param category is an string
	@param amount is a double value
	@param description is an string
	*/

};

const int askTransaction() {

	int choice;

	std::cout << "Hey, i see you want make transaction save? :" << std::endl;
	std::cout << "1 : Yes!" << std::endl;
	std:: cout << "2 : No!" << std::endl;
	std::cout << "Enter your choice :" << std::endl;
	std::cin >> choice;

	while (choice < 1 || choice > 2) {
		std::cout << "Invalid choice. Please enter 1 or 2: ";
		std::cin >> choice;
	};
	
	switch (choice) {
	case 1:
		std::cout << "You chose YES\n";
		break;
	case 2:
		std::cout << "You chose NO\n";
		break;
	}
	return choice;
	
	return 0;
};

int main() {
	int userChoice = askTransaction();
};