/*Create a billing system for a hotel. Generate bills based on room type, number of nights,
and additional services like food or laundry.*/
#include <iostream>
#include <string>
using namespace std;
class HotelBilling {
private:
    double roomRates[3] = {1000, 1500, 2500}; 
    double foodCharge = 500;  
    double laundryCharge = 300; 
public:
    double calculateBill(int roomType, int nights, bool food, bool laundry) {
        double roomCost = roomRates[roomType] * nights;  
        double foodCost = food ? foodCharge : 0;  
        double laundryCost = laundry ? laundryCharge : 0;  
        return roomCost + foodCost + laundryCost;  
    }
      void generateBill(int roomType, int nights, bool food, bool laundry) {
        double total = calculateBill(roomType, nights, food, laundry);
        cout << "\n--- Hotel Bill ---\n";
        cout << "Room Type: " << (roomType == 0 ? "Single" : roomType == 1 ? "Double" : "Suite") << "\n";
        cout << "Nights: " << nights << "\n";
        cout << "Food: " << (food ? "Yes" : "No") << " | Laundry: " << (laundry ? "Yes" : "No") << "\n";
        cout << "Total Amount: Rs. " << total << "\n";
    }
};
int main() {
    HotelBilling billing;
    int roomType, nights;
    char foodChoice, laundryChoice;
    cout << "Enter Room Type (0: Single, 1: Double, 2: Suite): ";
    cin >> roomType;
    cout << "Enter Number of Nights: ";
    cin >> nights;
    cout << "Food required (Y/N): ";
    cin >> foodChoice;
    cout << "Laundry required (Y/N): ";
    cin >> laundryChoice;
    bool food = (foodChoice == 'Y' || foodChoice == 'y');
    bool laundry = (laundryChoice == 'Y' || laundryChoice == 'y');
    billing.generateBill(roomType, nights, food, laundry);
   return 0;
}