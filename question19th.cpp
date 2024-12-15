/*Develop a program to simulate a simple cricket match. Allow the user to input the number
of overs and simulate ball-by-ball action, including runs and wickets.*/
#include <iostream>
#include <cstdlib>// For rand() and srand() functions
#include <ctime>  // For time() function to seed random number generator
using namespace std;
class CricketMatch {
private:
    int totalOvers;
    int runs = 0;
    int wickets = 0;
public:
    CricketMatch(int overs) {
        totalOvers = overs;
    }
    void simulateMatch() {
        srand(time(0));    
        for (int over = 1; over <= totalOvers; ++over) {
            cout << "\nOver " << over << ": ";
            for (int ball = 1; ball <= 6; ++ball) {
                int ballOutcome = rand() % 11; 
                if (ballOutcome == 10) {  
                    cout << "Ball " << ball << ": WICKET! ";
                    wickets++;
                    if (wickets == 10) {
                        cout << "All out!\n";
                        return;
                    }
                } else {
                    cout << "Ball " << ball << ": " << ballOutcome << " runs, ";
                    runs += ballOutcome;
                }
            }
            cout << "\n";
        }
    }
    void displayScore() {
        cout << "\nFinal Score: " << runs << "/" << wickets << endl;
    }
};
int main() {
    int overs;
    cout << "Enter the number of overs: ";
    cin >> overs;
    CricketMatch match(overs);
    match.simulateMatch();
    match.displayScore();
    return 0;
}

//want more info about #include<cstdlib> & #include<ctime> libraries from chirag sir on monday