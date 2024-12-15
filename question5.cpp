/*Simulate a banking queue system. Allow customers to join the queue and be served one at
a time. Implement priority servicing for senior citizens.*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Customer {
public:
    string name;
    int age;
    bool isSenior;
    Customer(string n, int a) : name(n), age(a), isSenior(a >= 60) {}
};
class BankQueue {
private:
    queue<Customer> priorityQueue, normalQueue;
public:
    void joinQueue(Customer c) {
        if (c.isSenior)
            priorityQueue.push(c);
        else
            normalQueue.push(c);
    }
void serveCustomer() {
        if (!priorityQueue.empty()) {
            Customer c = priorityQueue.front(); priorityQueue.pop();
            cout << "Serving senior: " << c.name << ", Age: " << c.age << endl;
        } else if (!normalQueue.empty()) {
            Customer c = normalQueue.front(); normalQueue.pop();
            cout << "Serving customer: " << c.name << ", Age: " << c.age << endl;
        } else {
            cout << "No customers to serve.\n";
        }
    }
     void queueStatus() {
        cout << "Priority Queue: " << priorityQueue.size() << ", Normal Queue: " << normalQueue.size() << endl;
    }
};
int main() {
    BankQueue bq;
    string name;
    int age, option;
    while (1) {
        cout << "\n1. Join Queue";
        cout<<"\n2. Serve Customer";
        cout<<"\n3. View Queue Status";
        cout<<"\n4. Exit";
        cout<<"\nChoose an option: ";
        cin >> option;
        cin.ignore();
        if (option == 1) {
            cout << "Enter name: "; getline(cin, name);
            cout << "Enter age: "; cin >> age;
            bq.joinQueue(Customer(name, age));
        } else if (option == 2) {
            bq.serveCustomer();
        } else if (option == 3) {
            bq.queueStatus();
        } else if (option == 4) {
            break;
        } else {
            cout << "Invalid option.\n";
        }
    }
    return 0;
}
