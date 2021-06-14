// Nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int aiPicks(int matchAmount);

int main()
{
    int totalMatches = 24;
    string matchGraph = "|";

    while (totalMatches > 0) {
        cout << "Total amount of matches: " << totalMatches << endl;
        for (int i = 0; i < totalMatches; ++i) {
            std::cout << "|";
        }
        std::cout << std::endl;
        cout << "Pick a number from 1 to 3" << endl;

        int i;
        cin >> i;

        if (i > 0 && i < 4) {
            totalMatches -= i;

            if (totalMatches < 1) {
                cout << "You lose!" << endl;
                break;
            }

            totalMatches = aiPicks(totalMatches);
        }

        else cout << "Invalid number" << endl;
    }

    cout << "GAME OVER" << endl;
}

int aiPicks(int matchAmount) {
    cout << "AI is picking a number..." << endl;

    if (matchAmount == 1) {
        matchAmount -= 1;
        cout << "AI picked: " << 1 << endl;
        cout << "You win!" << endl;
    }

    else if (matchAmount == 2) {
        matchAmount -= 1;
        cout << "AI picked: " << 1 << endl;
    }

    else if (matchAmount == 3) {
        matchAmount -= 2;
        cout << "AI picked: " << 2 << endl;
    }

    else {
        int randomPick;
        randomPick = rand() % 3 + 1;
        cout << "AI picked: " << randomPick << endl;
        matchAmount -= randomPick;
    }

    return matchAmount;
}

