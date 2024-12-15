/*Implement a program to collect customer feedback for a hotel. Allow users to rate their stay
and provide comments. Display average ratings and the most common feedback.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class HotelFeedback {
private:
    vector<int> ratings;
    vector<string> comments;
public:
    void collectFeedback() {
        int rating;
        string comment;
        cout << "Enter rating (1-5): ";
        cin >> rating;
        cin.ignore();
        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Please enter between 1 and 5.\n";
            return;
        }
        cout << "Enter comment: ";
        getline(cin, comment);
        ratings.push_back(rating);
        comments.push_back(comment);
    }
    void displayAverageRating() {
        if (ratings.empty()) {
            cout << "No feedback available yet.\n";
            return;
        }
        double total = 0;
        for (int rating : ratings) total += rating;
        cout << "Average Rating: " << total / ratings.size() << endl;
    }
    void displayMostCommonFeedback() {
        if (comments.empty()) {
            cout << "No feedback available yet.\n";
            return;
        }
        vector<string> uniqueComments = comments;
        sort(uniqueComments.begin(), uniqueComments.end());
        uniqueComments.erase(unique(uniqueComments.begin(), uniqueComments.end()), uniqueComments.end());
        string mostCommon;
        int maxCount = 0;
        for (const string& comment : uniqueComments) {
            int count = :: count(comments.begin(), comments.end(), comment);
            if (count > maxCount) {
                mostCommon = comment;
                maxCount = count;
            }
        }
        cout << "Most Common Feedback: \"" << mostCommon << "\" with " << maxCount << " occurrences.\n";
    }
};
int main() {
    HotelFeedback feedback;
    int choice;
    while (true) {
        cout << "\n1. Submit Feedback\n2. Average Rating\n3. Most Common Feedback\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: feedback.collectFeedback(); break;
            case 2: feedback.displayAverageRating(); break;
            case 3: feedback.displayMostCommonFeedback(); break;
            case 4: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}