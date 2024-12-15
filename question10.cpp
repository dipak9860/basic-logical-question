/*Implement a system for booking tickets for a concert or sports event. Ensure seat categories
like VIP, premium, and general admission are handled separately.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Event {
public:
    string category;
    int availableSeats;
    Event(string cat, int seats) : category(cat), availableSeats(seats) {}
    void displayCategory() {
        cout << category << " | Seats available: " << availableSeats << endl;
    }
    bool bookSeats(int numSeats) {
        if (numSeats <= availableSeats) {
            availableSeats -= numSeats;
            return true;
        }
        return false;
    }
};
class TicketBooking {
private:
    vector<Event> events;
public:
    TicketBooking() {
        events.push_back(Event("VIP", 10));
        events.push_back(Event("Premium", 20));
        events.push_back(Event("General Admission", 50));
    }
    void showCategories() {
        for (auto &event : events) event.displayCategory();
    }
    void bookTicket() {
        string category;
        int seats;
        cout << "Enter seat category (VIP, Premium, General Admission): ";
        cin >> category;
        cout << "Enter number of seats: ";
        cin >> seats;
        bool booked = false;
        for (auto &event : events) {
            if (event.category == category) {
                booked = event.bookSeats(seats);
                break;
            }
        }
        if (booked) {
            cout << seats << " seats booked successfully in " << category << " category.\n";
            cout << "Generating ticket receipt...\n";
            cout << "Category: " << category << " | Seats: " << seats << endl;
        } else {
            cout << "Booking failed. Not enough available seats.\n";
        }
    }
};
int main() {
    TicketBooking bookingSystem;
    int choice;
    while (true) {
        cout << "\n1. Show Categories\n2. Book Ticket\n3. Exit\nChoose an option: ";
        cin >> choice;
        if (choice == 1) bookingSystem.showCategories();
        else if (choice == 2) bookingSystem.bookTicket();
        else break;
    }
    return 0;
}