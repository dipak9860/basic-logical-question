/*Design a bus ticket booking system. Display available routes and seat availability. Allow users
to book multiple tickets and generate a ticket receipt.*/
#include <bits/stdc++.h>
using namespace std;
class Bus {
public:
    string route;
    int availableSeats;
    Bus(string r, int seats) : route(r), availableSeats(seats) {}
    void displayRoute() {
        cout << route << " | Seats available: " << availableSeats << endl;
    }
    bool bookSeats(int numSeats) {
        if (numSeats <= availableSeats) {
            availableSeats -= numSeats;
            return true;
        }
        return false;
    }
};
class BusBooking {
private:
    vector<Bus> buses;
public:
    BusBooking() {
        buses.push_back(Bus("Route 101 - City A to City B", 10));
        buses.push_back(Bus("Route 202 - City B to City C", 5));
        buses.push_back(Bus("Route 303 - City A to City D", 8));
    }
    void showRoutes() {
        for (auto &bus : buses) bus.displayRoute();
    }
    void bookTicket() {
        string route;
        int seats;
        cout << "Enter route to book (e.g., 'Route 101'): ";
        cin.ignore();
        getline(cin, route);
        cout << "Enter number of seats: ";
        cin >> seats;
        bool booked = false;
        for (auto &bus : buses) {
            if (bus.route == route) {
                booked = bus.bookSeats(seats);
                break;
            }
        }
        if (booked) {
            cout << seats << " seats booked successfully on " << route << ".\n";
            cout << "Generating ticket receipt...\n";
            cout << "Route: " << route << " | Seats: " << seats << "\n";
        } else {
            cout << "Booking failed. Not enough available seats.\n";
        }
    }
};
int main() {
    BusBooking bookingSystem;
    int choice;
    while (true) {
        cout << "\n1. Show Routes";
        cout<<"\n2. Book Ticket";
        cout<<"\n3. Exit\nChoose an option: ";
        cin >> choice;
        if (choice == 1) bookingSystem.showRoutes();
        else if (choice == 2) bookingSystem.bookTicket();
        else break;
    }
    return 0;
}