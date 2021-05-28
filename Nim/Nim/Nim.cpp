// Nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int aiPick(int m);

int main()
{
    int matches = 24;
    string match = "|";

    while (matches > 0)
    {
        cout << "Number of matches: " << matches << endl;
        for (int i = 0; i < matches; ++i) 
            std::cout << "|";
        std::cout << std::endl;
        cout << "Pick a number from 1 to 3" << endl;

        int i;
        cin >> i;

        if (i > 0 && i < 4)
        {
            matches -= i;

            if (matches < 1)
            {
                cout << "You lose!" << endl;
                break;
            }

            matches = aiPick(matches);
        }
        else cout << "The number you picked is out of range. Try another one." << endl;
    }
    cout << "GAME OVER" << endl;
}

int aiPick(int matchAmount) {
    cout << "AI is picking a number now" << endl;

    if (matchAmount == 1)
    {
        matchAmount -= 1;
        cout << "AI has removed the following matches amount: " << 1 << endl;
        cout << "You win!" << endl;
    }
    else if (matchAmount == 2) 
    {
        matchAmount -= 1;
        cout << "AI removed this amount: " << 1 << endl;
    }
        
    else if (matchAmount == 3) 
    {
        matchAmount -= 2;
        cout << "AI removed this amount: " << 2 << endl;
    }
        
    else 
    {
        int r;
        r = rand() % 3 + 1;
        cout << "AI removed this amount: " << r << endl;
        matchAmount -= r;
    }
    return matchAmount;
}