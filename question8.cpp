/*Develop a program to simulate a flight booking system. Include features for searching flights,
booking tickets, and managing passenger details. Add functionality for class selection
(economy/business).*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Flight {
public:
    string flightNo;
    string destination;
    int availableSeatsEconomy, availableSeatsBusiness;
    Flight(string fNo, string dest, int econSeats, int busSeats) 
        : flightNo(fNo), destination(dest), availableSeatsEconomy(econSeats), availableSeatsBusiness(busSeats) {}
    void display() {
        cout << flightNo << " to " << destination << " | Economy: " << availableSeatsEconomy << " seats | Business: " << availableSeatsBusiness << " seats\n";
    }
        bool bookSeat(string cls) {
        if (cls == "economy" && availableSeatsEconomy > 0) {
            availableSeatsEconomy--;
            return true;
        } else if (cls == "business" && availableSeatsBusiness > 0) {
            availableSeatsBusiness--;
            return true;
        }
        return false;
    }
};
class FlightBooking {
private:
    vector<Flight> flights;
public:
    FlightBooking() {
        flights.push_back(Flight("AA123", "New York", 5, 2));
        flights.push_back(Flight("BA456", "London", 3, 1));
    }
    void searchFlights() {
        for (auto &f : flights) f.display();
    }
    void bookTicket() {
        string flightNo, cls;
        cout << "Enter flight number: ";
        cin >> flightNo;
        cout << "Select class (economy/business): ";
        cin >> cls;
        bool booked = false;
        for (auto &f : flights) {
            if (f.flightNo == flightNo) {
                booked = f.bookSeat(cls);
                break;
            }
        }
        if (booked) cout << "Booking successful!\n";
        else cout << "Booking failed. Check availability or class.\n";
    }
};
int main() {
    FlightBooking fb;
    int choice;
    while (1) {
        cout << "\n1. Search Flights\n2. Book Ticket\n3. Exit\nChoose an option: ";
        cin >> choice;
       if (choice == 1) fb.searchFlights();
        else if (choice == 2) fb.bookTicket();
        else break;
    }
    return 0;
}