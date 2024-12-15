/*Build a program to keep track of the score in a tennis match. Implement scoring rules for
sets and games and display the winner dynamically.*/
#include <iostream>
#include <string>
using namespace std;
class TennisMatch {
private:
    int player1Games = 0, player2Games = 0;
    int player1Sets = 0, player2Sets = 0;
    int maxGamesInSet = 6;
public:
    void playGame() {
        int player1Points = 0, player2Points = 0;
        while (player1Points < 4 && player2Points < 4) {
            int pointWinner = rand() % 2; 
            if (pointWinner == 0) player1Points++;
            else player2Points++;
        }
        if (player1Points > player2Points) {
            cout << "Player 1 wins the game\n";
            player1Games++;
        } else {
            cout << "Player 2 wins the game\n";
            player2Games++;
        }
    }
void playSet() {
        player1Games = 0;
        player2Games = 0;
                while (player1Games < maxGamesInSet && player2Games < maxGamesInSet) {
            cout << "\nNew Game Started\n";
            playGame();
            if (player1Games == maxGamesInSet) {
                cout << "Player 1 wins the set\n";
                player1Sets++;
                return;
            } else if (player2Games == maxGamesInSet) {
                cout << "Player 2 wins the set\n";
                player2Sets++;
                return;
            }
        }
    }
    void displayScore() {
        cout << "\nCurrent Score: Player 1 - " << player1Sets << " sets, " << player1Games << " games\n";
        cout << "Player 2 - " << player2Sets << " sets, " << player2Games << " games\n";
    }
    void matchOver() {
        if (player1Sets > player2Sets) {
            cout << "\nPlayer 1 wins the match!\n";
        } else if (player2Sets > player1Sets) {
            cout << "\nPlayer 2 wins the match!\n";
        }
    }
};
int main() {
    srand(time(0));  
    TennisMatch match;
    int setsToPlay;
    cout << "Enter the number of sets to play: ";
    cin >> setsToPlay;
    for (int i = 0; i < setsToPlay; ++i) {
        cout << "\nSet " << i + 1 << " starting...\n";
        match.playSet();
        match.displayScore();
    }
    match.matchOver();
   return 0;
}