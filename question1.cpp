/*Design a program to manage a bank account. Implement functionality for depositing money,
withdrawing money, checking account balance, and viewing transaction history. Ensure
withdrawals are denied if the balance is insufficient.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BankAccount {
private:
    double balance = 0.0;
    vector<string> transactions;
public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposited: $" + to_string(amount));
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdrew: $" + to_string(amount));
            cout << "Withdrew: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }
    void viewTransactionHistory() {
        cout << "Transaction History:\n";
        for (const string& transaction : transactions) {
            cout << transaction << endl;
        }
    }
};
int main() {
    BankAccount account;
    int choice;
    double amount;
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.viewTransactionHistory();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
   return 0;
}