/*Write a program to manage train ticket bookings. Include functionalities to book, modify,
and cancel tickets. Assign seats dynamically and allow users to view seat layouts.*/
#include <iostream>
#include <vector>
using namespace std;
class Train {
private:
    vector<int> seats;
    const int seatLimit = 5;
public:
    Train(int totalSeats) {
        seats.resize(totalSeats, 0);
    }
    void showSeats() {
        for (int i = 0; i < seats.size(); i++) {
            cout << (seats[i] ? "X" : "O") << " ";
        }
        cout << endl;
    }
    bool bookTickets(int numSeats) {
        if (numSeats > seatLimit) {
            cout << "Cannot book more than " << seatLimit << " seats.\n";
            return false;
        }
        int booked = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0 && booked < numSeats) {
                seats[i] = 1;
                booked++;
            }
        }
        if (booked == numSeats) {
            cout << numSeats << " seats booked.\n";
            return true;
        } else {
            cout << "Not enough seats.\n";
            return false;
        }
    }
    bool cancelTickets(int numSeats) {
        int cancelled = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1 && cancelled < numSeats) {
                seats[i] = 0;
                cancelled++;
            }
        }
        if (cancelled == numSeats) {
            cout << numSeats << " seats cancelled.\n";
            return true;
        } else {
            cout << "Not enough booked seats.\n";
            return false;
        }
    }
    bool modifyBooking(int oldSeats, int newSeats) {
        if (cancelTickets(oldSeats)) {
            return bookTickets(newSeats);
        }
        return false;
    }
};
int main() {
    Train train(20);
    int option, numSeats;
    while (true) {
        cout << "\n1. View Seats\n2. Book\n3. Cancel\n4. Modify\n5. Exit\n";
        cin >> option;
    if (option == 1) train.showSeats();
        else if (option == 2) 
        { cout << "Seats to book: "; 
        cin >> numSeats;
         train.bookTickets(numSeats); 
         }
        else if (option == 3) { cout << "Seats to cancel: ";
         cin >> numSeats;
          train.cancelTickets(numSeats); 
          }
        else if (option == 4) { int oldSeats, newSeats; 
        cout << "Cancel: ";
         cin >> oldSeats; 
        cout << "Book: "; 
        cin >> newSeats;
         train.modifyBooking(oldSeats, newSeats); 
        }
        else if (option == 5) break;
        else cout << "Invalid option.\n";
    }
    return 0;
}
