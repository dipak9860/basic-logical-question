/*Write a program to manage hotel room reservations. Allow users to check room availability,
book rooms, and cancel reservations. Handle different room types like single, double, and
suite*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Hotel {
private:
    map<string, int> rooms;
public:
    Hotel() {
        rooms["Single"] = 5;  
        rooms["Double"] = 3;  
        rooms["Suite"] = 2;  
    }
    void checkAvailability() {
        cout << "Room Availability:\n";
        for (auto& room : rooms) {
            cout << room.first << ": " << room.second << " available\n";
        }
    }
    void bookRoom(string roomType) {
        if (rooms[roomType] > 0) {
            rooms[roomType]--;
            cout << roomType << " room booked successfully!\n";
        } else {
            cout << "Sorry, no " << roomType << " rooms available.\n";
        }
    }
    void cancelReservation(string roomType) {
        if (rooms[roomType] < 5) {
            rooms[roomType]++;
            cout << roomType << " room reservation canceled successfully!\n";
        } else {
            cout << "No reservations to cancel for " << roomType << " rooms.\n";
        }
    }
};
int main() {
    Hotel hotel;
    int choice;
    string roomType;
    while (true) {
        cout << "\n1. Check Availability\n2. Book Room\n3. Cancel Reservation\n4. Exit\nEnter choice: ";
        cin >> choice;
       switch (choice) {
            case 1:
                hotel.checkAvailability();
                break;
            case 2:
                cout << "Enter room type (Single/Double/Suite): ";
                cin >> roomType;
                hotel.bookRoom(roomType);
                break;
            case 3:
                cout << "Enter room type to cancel (Single/Double/Suite): ";
                cin >> roomType;
                hotel.cancelReservation(roomType);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}