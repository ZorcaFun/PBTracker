#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

struct Transaction {
    int id;                 // Unique transaction ID
    std::string date;       // Date of the transaction
    std::string type;       // "Income" or "Expense"
    std::string category;   // e.g. "Food", "Salary"
    double amount;          // Amount of the transaction
    std::string description;// Description of the transaction
};

// Function to get a Transaction filled by user input
Transaction getTransactionFromUser(int nextId) {
    Transaction t;
    t.id = nextId;

    // Clear input buffer before getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter transaction date (e.g. 2024-05-01): ";
    std::getline(std::cin, t.date);

    while (true) {
        std::cout << "Enter transaction type (Income or Expense): ";
        std::getline(std::cin, t.type);
        if (t.type == "Income" || t.type == "Expense") {
            break;
        }
        std::cout << "Invalid type. Please enter either 'Income' or 'Expense'.\n";
    }

    std::cout << "Enter transaction category (e.g. Food, Salary): ";
    std::getline(std::cin, t.category);

    while (true) {
        std::cout << "Enter transaction amount: ";
        std::string amountStr;
        std::getline(std::cin, amountStr);
        try {
            t.amount = std::stod(amountStr);
            break;
        }
        catch (...) {
            std::cout << "Invalid amount. Please enter a valid number.\n";
        }
    }

    std::cout << "Enter transaction description: ";
    std::getline(std::cin, t.description);

    return t;
}

// Function to display all transactions
void showTransactionHistory(const std::vector<Transaction>& transactions) {
    if (transactions.empty()) {
        std::cout << "No transactions found.\n";
        return;
    }

    std::cout << "\nTransaction History:\n";
    std::cout << "ID | Date       | Type    | Category   | Amount     | Description\n";
    std::cout << "-----------------------------------------------------------------------\n";
    for (const auto& t : transactions) {
        std::cout << t.id << "  | "
            << t.date << " | "
            << t.type << "  | "
            << t.category << "     | "
            << std::fixed << std::setprecision(2) << t.amount << "      | "
            << t.description << "\n";
    }
}

// Function to remove a transaction by ID
bool removeTransactionById(std::vector<Transaction>& transactions, int id) {
    auto it = std::find_if(transactions.begin(), transactions.end(),
        [id](const Transaction& t) { return t.id == id; });
    if (it != transactions.end()) {
        transactions.erase(it);
        return true;
    }
    return false;
}

int main() {
    std::vector<Transaction> transactions;
    int nextId = 1; // Start transaction IDs at 1

    std::cout << R"(PBTracker by ZorcaFun ---> Version: 2025.5.13.EARLYBUILD)" << std::endl;

    while (true) {
        std::cout << "\nChoose an option:\n"
            << "1. Add Transaction\n"
            << "2. Remove Transaction\n"
            << "3. Show Transaction History\n"
            << "4. Exit\n"
            << "Enter your choice: ";

        int userChoice;
        std::cin >> userChoice;

        // Validate input
        while (std::cin.fail() || userChoice < 1 || userChoice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
            std::cin >> userChoice;
        }

        if (userChoice == 1) {
            Transaction t = getTransactionFromUser(nextId++);
            transactions.push_back(t);
            std::cout << "Transaction added successfully!\n";
        }
        else if (userChoice == 2) {
            std::cout << "Enter the ID of the transaction to remove: ";
            int idToRemove;
            std::cin >> idToRemove;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline after number input

            if (removeTransactionById(transactions, idToRemove)) {
                std::cout << "Transaction with ID " << idToRemove << " removed.\n";
            }
            else {
                std::cout << "Transaction ID not found.\n";
            }
        }
        else if (userChoice == 3) {
            showTransactionHistory(transactions);
        }
        else if (userChoice == 4) {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }
    }

    return 0;
}