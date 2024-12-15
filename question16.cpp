/*Create a program to simulate a cricket scoreboard. Allow users to enter runs, wickets, and
overs bowled. Display the current score and strike rates of the batsmen.*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class CricketScoreboard {
private:
    int totalRuns = 0, totalWickets = 0, totalOvers = 0;
    int currentBatsmanRuns[2] = {0, 0};
    int ballsFaced[2] = {0, 0};
    int currentBatsman = 0;  
public:
    void addRun(int runs) {
        if (runs == 0) return;
        totalRuns += runs;
        currentBatsmanRuns[currentBatsman] += runs;
        ballsFaced[currentBatsman]++;
        if (runs % 2 != 0) currentBatsman = 1 - currentBatsman; 
    }
    void addWicket() {
        totalWickets++;
        currentBatsman = 1 - currentBatsman;  
    }
    void addOver() {
        totalOvers++;
    }
    void displayScoreboard() {
        double strikeRate1 = (ballsFaced[0] > 0) ? (currentBatsmanRuns[0] * 100.0 / ballsFaced[0]) : 0;
        double strikeRate2 = (ballsFaced[1] > 0) ? (currentBatsmanRuns[1] * 100.0 / ballsFaced[1]) : 0;
        cout << "\n--- Cricket Scoreboard ---\n";
        cout << "Total Runs: " << totalRuns << "/" << totalWickets << endl;
        cout << "Overs: " << totalOvers << endl;
        cout << "Batsman 1: Runs = " << currentBatsmanRuns[0] << ", Strike Rate = " << fixed << setprecision(2) << strikeRate1 << endl;
        cout << "Batsman 2: Runs = " << currentBatsmanRuns[1] << ", Strike Rate = " << fixed << setprecision(2) << strikeRate2 << endl;
    }
};
int main() {
    CricketScoreboard scoreboard;
    int choice, runs;
    while (true) {
        cout << "\n1. Add Run\n2. Add Wicket\n3. Add Over\n4. Display Scoreboard\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter runs scored: ";
                cin >> runs;
                scoreboard.addRun(runs);
                break;
            case 2:
                scoreboard.addWicket();
                break;
            case 3:
                scoreboard.addOver();
                break;
            case 4:
                scoreboard.displayScoreboard();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}