#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void showQuote() {
    string quotes[] = {
        "Believe you can, and you’re halfway there.",
        "Every small step counts – progress is progress.",
        "You are stronger than you think.",
        "Don’t give up. Great things take time.",
        "Your feelings are valid. Take it one day at a time.",
        "Breathe. Relax. You’re doing fine.",
        "Even stars need darkness to shine ?."
    };
    int n = sizeof(quotes) / sizeof(quotes[0]);
    srand(time(0));
    int index = rand() % n;
    cout << "\n Quote of the Day: " << quotes[index] << endl;
}

void chatBot() {
    string input;
    cout << "\nHow are you feeling today? ";
    getline(cin, input);

    if (input.find("sad") != string::npos) {
        cout << "I’m sorry you’re feeling low. Remember, even the darkest night will end and the sun will rise 	.\n";
    } else if (input.find("stressed") != string::npos) {
        cout << "Take a deep breath with me... inhale 4 sec, hold 4 sec, exhale 4 sec .\n";
    } else if (input.find("happy") != string::npos) {
        cout << "That’s wonderful! Happiness looks great on you .\n";
    } else if (input.find("lonely") != string::npos) {
        cout << "You are not alone. I’m here for you .\n";
    } else if (input.find("anxious") != string::npos) {
        cout << "Try grounding: 5 things you see, 4 touch, 3 hear, 2 smell, 1 taste .\n";
    } else {
        cout << "I may not understand fully, but I care about how you feel .\n";
    }
}


void logMood() {
    int mood;
    cout << "\nRate your mood today (1=Very Sad, 5=Very Happy): ";
    cin >> mood;

    ofstream file("mood_log.txt", ios::app);
    if (file.is_open()) {
        file << "Mood: " << mood << endl;
        cout << "~ Mood logged successfully!\n";
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n====== Mental Health Companion ======\n";
        cout << "1. Talk to Companion\n";
        cout << "2. Log Mood\n";
        cout << "3. Show Motivational Quote\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: chatBot(); break;
            case 2: logMood(); break;
            case 3: showQuote(); break;
            case 4: cout << "Goodbye!! Stay positive!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
