/**/
#include <iostream>
#include <string>
using namespace std;
class Hotel {
private:
    string guests[5];  
    double roomRates[5] = {1000, 1500, 2000, 2500, 3000};  
    bool roomsAvailable[5] = {true, true, true, true, true};  
public:
    void checkIn() {
        string name;
        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin, name);    
        for (int i = 0; i < 5; i++) {
            if (roomsAvailable[i]) {
                guests[i] = name;
                roomsAvailable[i] = false;
                cout << "Room " << i + 1 << " assigned to " << name << ".\n";
                return;
            }
        }
        cout << "Sorry, no rooms available.\n";
    }
    void checkOut() {
        int roomNumber;
        cout << "Enter room number to check out (1-5): ";
        cin >> roomNumber;   
        if (roomNumber < 1 || roomNumber > 5 || roomsAvailable[roomNumber - 1]) {
            cout << "Invalid room number or room already vacant.\n";
            return;
        }
        roomsAvailable[roomNumber - 1] = true;
        cout << "Room " << roomNumber << " is now available.\n";
        double bill = roomRates[roomNumber - 1];
        cout << "Total bill for Room " << roomNumber << ": Rs. " << bill << endl;
        guests[roomNumber - 1] = "";  
    }
    void viewGuests() {
        cout << "\n--- Guest List ---\n";
        for (int i = 0; i < 5; i++) {
            cout << "Room " << i + 1 << ": " << (guests[i].empty() ? "Empty" : guests[i]) << endl;
        }
    }
};

int main() {
    Hotel hotel;
    int choice;
    while (true) {
        cout << "\n1. Check-in";
        cout<<"\n2. Check-out";
        cout<<"\n3. View Guests";
        cout<<"\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
             hotel.checkIn();
              break;
            case 2:
             hotel.checkOut();
              break;
            case 3:
             hotel.viewGuests();
              break;
            case 4: 
            return 0;
            default:
             cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}