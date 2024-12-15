/*Create a program to simulate an ATM system. Include options to check balance, withdraw
money, deposit money, and change the PIN. Implement limits on daily withdrawal amounts.*/
#include <iostream>
using namespace std;
#define DAILY_LIMIT 10000
float balance = 5000.0, daily_withdrawn = 0.0;
int pin = 1234, entered_pin, pin_tries = 0;
void check_balance() { cout << "Balance: " << balance << endl; }
void deposit() { float amount; cout << "Deposit: "; cin >> amount; balance += (amount > 0) ? amount : 0; cout << "New balance: " << balance << endl; }
void withdraw() { float amount; cout << "Withdraw: "; cin >> amount;
    if (amount > 0 && amount <= balance && amount + daily_withdrawn <= DAILY_LIMIT) {
        balance -= amount; daily_withdrawn += amount; cout << "New balance: " << balance << endl;
    } else cout << "Invalid transaction." << endl;
}
void change_pin() { cout << "New PIN: "; 
cin >> pin;
 cout << "PIN changed." << endl; }
int main() {
    while (pin_tries < 3) {
        cout << "Enter PIN: "; cin >> entered_pin;
        if (entered_pin == pin)
         break;
        pin_tries++; 
        if (pin_tries == 3) { cout << "Too many attempts. Exiting...\n"; return 0; }
    }
    int option;
    while (1) {
        cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Change PIN\n5. Exit\nChoice: ";
        cin >> option;
        if (option == 1) check_balance();
        else if (option == 2) deposit();
        else if (option == 3) withdraw();
        else if (option == 4) change_pin();
        else if (option == 5) break;
        else cout << "Invalid option.\n";
    }
    return 0;
}
