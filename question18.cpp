/*Write a program to track player statistics like runs scored, wickets taken, and matches
played. Allow users to search for and display individual player stats.*/
#include <iostream>
#include <string>
using namespace std;
    struct Player {
    string name;
    int runs = 0;
    int wickets = 0;
    int matches = 0;
    void updateStats(int r, int w, int m) {
        runs += r;
        wickets += w;
        matches += m;
    }
    void displayStats() {
        cout << "Player: " << name << endl;
        cout << "Matches Played: " << matches << endl;
        cout << "Runs Scored: " << runs << endl;
        cout << "Wickets Taken: " << wickets << endl;
    }
};
    int main() {
    int n;
    cout << "Enter number of players: ";
    cin >> n;
    Player players[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter name of player " << i + 1 << ": ";
        cin >> players[i].name;
    }
    int m;
    cout << "Enter number of matches: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string playerName;
        int runs, wickets;
        cout << "Enter match details (PlayerName Runs Wickets): ";
        cin >> playerName >> runs >> wickets;
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (players[j].name == playerName) {
                players[j].updateStats(runs, wickets, 1);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Player not found: " << playerName << endl;
        }
    }
    string searchPlayer;
    cout << "Enter player name to view stats: ";
    cin >> searchPlayer;
    bool found = false;
        for (int i = 0; i < n; ++i) {
        if (players[i].name == searchPlayer) {
            players[i].displayStats();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Player not found!" << endl;
    }
   return 0;
}