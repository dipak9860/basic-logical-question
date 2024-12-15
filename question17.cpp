/*Implement a points table for a cricket tournament. Calculate and display points, net run
rate, and rankings based on match results.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Team {
    string name;
    int points = 0;
    int runsScored = 0;
    int runsAgainst = 0;
    int wicketsTaken = 0;
    int wicketsLost = 0;
    int netRunRate = 0;    
    void calculateNRR() {
        if (runsAgainst == 0) netRunRate = runsScored;  
        else netRunRate = runsScored - runsAgainst;
    }
};
bool compareTeams(const Team &a, const Team &b) {
    if (a.points != b.points) return a.points > b.points;
    if (a.netRunRate != b.netRunRate) return a.netRunRate > b.netRunRate;
    return a.name < b.name; 
}
int main() {
    int n;
    cout << "Enter number of teams: ";
    cin >> n;
    vector<Team> teams(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter name of team " << i+1 << ": ";
        cin >> teams[i].name;
    }
    int m;
    cout << "Enter number of matches: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string team1, team2;
        int score1, score2, wickets1, wickets2;
        cout << "Enter match " << i+1 << " details (Team1 Team2 Score1 Score2 Wickets1 Wickets2): ";
        cin >> team1 >> team2 >> score1 >> score2 >> wickets1 >> wickets2;
        int t1 = -1, t2 = -1;
        for (int j = 0; j < n; ++j) {
            if (teams[j].name == team1) t1 = j;
            if (teams[j].name == team2) t2 = j;
        }
        if (score1 > score2) {
            teams[t1].points += 2;  
        } else if (score2 > score1) {
            teams[t2].points += 2;  
        } else {
            teams[t1].points += 1;  
            teams[t2].points += 1;  
        }
        teams[t1].runsScored += score1;
        teams[t2].runsScored += score2;
        teams[t1].runsAgainst += score2;
        teams[t2].runsAgainst += score1;
        teams[t1].wicketsTaken += wickets1;
        teams[t2].wicketsTaken += wickets2;
        teams[t1].wicketsLost += wickets2;
        teams[t2].wicketsLost += wickets1;
    }
    for (int i = 0; i < n; ++i) {
        teams[i].calculateNRR();
    }
       sort(teams.begin(), teams.end(), compareTeams);
    cout << "\nPoints Table:\n";
    cout << "Rank | Team Name | Points | NRR\n";
    for (int i = 0; i < n; ++i) {
        cout << i+1 << " | " << teams[i].name << " | " << teams[i].points << " | " << teams[i].netRunRate << endl;
    }
    return 0;
}