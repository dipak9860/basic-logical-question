/*Create a ticket booking system for a cinema hall. Let users view seat availability, select seats,
book tickets, and cancel bookings. Handle constraints like seat limits per user.*/
#include <iostream>
#include <vector>
using namespace std;
class Cinema {
private:
    vector<int> seats;  
    const int seatLimit = 5;
public:
    Cinema(int totalSeats) {
        seats.resize(totalSeats, 0); 
    }
    void showSeats() {
        for (int i = 0; i < seats.size(); i++) {
            cout << (seats[i] == 0 ? "O" : "X") << " ";  
        }
        cout << endl;
    }
    bool bookSeats(int numSeats) {
        if (numSeats > seatLimit) {
            cout << "Cannot book more than " << seatLimit << " seats.\n";
            return false;
        }
    int availableSeats = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) availableSeats++;
        }
        if (availableSeats < numSeats) {
            cout << "Not enough available seats.\n";
            return false;
        }
    int booked = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0 && booked < numSeats) {
                seats[i] = 1; 
                booked++;
            }
        }
        cout << numSeats << " seats booked successfully!\n";
        return true;
    }
    bool cancelSeats(int numSeats) {
        int bookedSeats = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) bookedSeats++;
        }
        if (bookedSeats < numSeats) {
            cout << "Not enough booked seats to cancel.\n";
            return false;
        }
    int cancelled = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1 && cancelled < numSeats) {
                seats[i] = 0; 
                cancelled++;
            }
        }
        cout << numSeats << " seats cancelled successfully!\n";
        return true;
    }
};
int main() {
    Cinema cinema(20); 
    int option, numSeats;
    while (1) {
        cout << "\n1. View Seats\n2. Book Tickets\n3. Cancel Booking\n4. Exit\nChoose an option: ";
        cin >> option;
        if (option == 1) {
            cinema.showSeats();
        } else if (option == 2) {
            cout << "Enter number of seats to book: ";
            cin >> numSeats;
            if (!cinema.bookSeats(numSeats)) {
                cout << "Booking failed.\n";
            }
        } else if (option == 3) {
            cout << "Enter number of seats to cancel: ";
            cin >> numSeats;
            if (!cinema.cancelSeats(numSeats)) {
                cout << "Cancellation failed.\n";
            }
       } 
       else if (option == 4) {
            break;
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}