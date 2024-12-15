/*Develop a program to manage table reservations in a hotel restaurant. Allow users to book
tables for specific time slots and cancel bookings if needed.*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class RestaurantReservation {
private:
    map<string, bool> tableReservations;  
public:
    RestaurantReservation() {
        string times[] = {"12:00 PM", "1:00 PM", "2:00 PM", "3:00 PM", "4:00 PM", "5:00 PM", "6:00 PM", "7:00 PM"};
        for (string time : times) {
            tableReservations[time] = false; 
        }
    }
    void bookTable() {
        string time;
        cout << "Enter time slot to book (e.g. 12:00 PM, 1:00 PM): ";
        cin >> time;
        if (tableReservations.find(time) != tableReservations.end()) {
            if (!tableReservations[time]) {
                tableReservations[time] = true;
                cout << "Table booked for " << time << " successfully!\n";
            } else {
                cout << "Sorry, this time slot is already booked.\n";
            }
        } else {
            cout << "Invalid time slot. Please try again.\n";
        }
    }
    void cancelBooking() {
        string time;
        cout << "Enter time slot to cancel booking (e.g. 12:00 PM, 1:00 PM): ";
        cin >> time;
        if (tableReservations.find(time) != tableReservations.end()) {
            if (tableReservations[time]) {
                tableReservations[time] = false;
                cout << "Booking for " << time << " canceled successfully.\n";
            } else {
                cout << "No booking found for this time slot.\n";
            }
        } else {
            cout << "Invalid time slot. Please try again.\n";
        }
    }
    void displayReservations() {
        cout << "\n--- Table Reservations ---\n";
        for (auto& reservation : tableReservations) {
            cout << reservation.first << ": " << (reservation.second ? "Booked" : "Available") << "\n";
        }
    }
};
int main() {
    RestaurantReservation restaurant;
    int choice;
    while (true) {
        cout << "\n1. Book Table\n2. Cancel Booking\n3. View Reservations\n4. Exit\nEnter choice: ";
        cin >> choice;        
        switch (choice) {
            case 1: restaurant.bookTable(); break;
            case 2: restaurant.cancelBooking(); break;
            case 3: restaurant.displayReservations(); break;
            case 4: return 0;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}