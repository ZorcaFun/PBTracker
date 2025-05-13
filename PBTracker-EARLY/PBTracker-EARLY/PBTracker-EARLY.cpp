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

	std::cout << "Hey, i see you want make transaction save? :";
	std::cout << "1 : Yes!";
	std:: cout << "2 : No!";
	std::cout << "Enter your choice :";
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "You choose YES";
	}

};