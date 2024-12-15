/*Build a loan EMI calculator. Take the loan amount, interest rate, and duration as inputs, and
compute the monthly EMI. Allow the user to view the total payable amount and interest paid.*/

#include <iostream>
#include <cmath>
using namespace std;
void calculate_emi(float loan_amount, float annual_rate, int months) {
    float monthly_rate = annual_rate / 12 / 100;
    float emi = (loan_amount * monthly_rate * pow(1 + monthly_rate, months)) / (pow(1 + monthly_rate, months) - 1);
    float total_payable = emi * months;
    float total_interest = total_payable - loan_amount;
    cout << "\nMonthly EMI: " << emi << endl;
    cout << "Total Payable Amount: " << total_payable << endl;
    cout << "Total Interest Paid: " << total_interest << endl;
}
int main() {
    float loan_amount, annual_rate;
    int months;
    cout << "Enter Loan Amount: ";
    cin >> loan_amount;
    cout << "Enter Annual Interest Rate (in %%): ";
    cin >> annual_rate;
    cout << "Enter Loan Duration (in months): ";
    cin >> months;
    calculate_emi(loan_amount, annual_rate, months);
    return 0;
}
