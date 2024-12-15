/*Write a program to calculate the maturity amount of a fixed deposit based on the principal
amount, rate of interest, and duration. Allow users to choose between simple and compound
interest.*/

#include <iostream>
#include <cmath> 
using namespace std;
double calculateSimpleInterest(double principal, double rate, int time) {
    return (principal * rate * time) / 100.0;
}
double calculateCompoundInterest(double principal, double rate, int time) {
    return principal * pow((1 + rate / 100.0), time) - principal;
}
void calculateMaturityAmount() {
    double principal, rate, interest, maturityAmount;
    int time, choice;
    cout << "\nEnter Principal Amount: $";
    cin >> principal;
    cout << "Enter Rate of Interest (in %): ";
    cin >> rate;
    cout << "Enter Duration (in years): ";
    cin >> time;
    cout << "\nChoose Interest Type:" << endl;
    cout << "1. Simple Interest" << endl;
    cout << "2. Compound Interest" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        interest = calculateSimpleInterest(principal, rate, time);
        maturityAmount = principal + interest;
        cout << "\nSimple Interest: $" << interest << endl;
        cout << "Maturity Amount: $" << maturityAmount << endl;
    } else if (choice == 2) {
        interest = calculateCompoundInterest(principal, rate, time);
        maturityAmount = principal + interest;
        cout << "\nCompound Interest: $" << interest << endl;
        cout << "Maturity Amount: $" << maturityAmount << endl;
    } else {
        cout << "Invalid choice! Please try again." << endl;
    }
}
int main() {
    cout << "Welcome to Fixed Deposit Maturity Calculator" << endl;
    char continueCalc;
    do {
        calculateMaturityAmount();
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueCalc;
    } while (continueCalc == 'y' || continueCalc == 'Y');
    cout << "\nThank you for using the Fixed Deposit Maturity Calculator. Goodbye!\n";
    return 0;
}
