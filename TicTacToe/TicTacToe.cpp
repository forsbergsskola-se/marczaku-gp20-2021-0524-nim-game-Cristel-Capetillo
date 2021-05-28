// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool freeSpots(string spots[9]) {
    int index = 0;
    while (true) {
        if (spots[index] == "?")
            return true;
        if (index == 8)
            return false;
        index++;
    }
}

bool playerTurn(string player, string spots[9]) {
    cout << player << "'s turn" << endl;
    int playerInput = 0;
    if (player == "O") {
        int result;
        while (true) {
            result = rand() % 8 + 0;
            if (spots[result] == "?") {
                playerInput = result;
                cout << player << " Selected spot: " << result << endl;
                break;
            }
        }
    }
    else {
        cout << "Type a number from 0 to 8 to take a spot on the grid" << endl;
        cin >> playerInput;
    }

    if (spots[playerInput] == "?") {
        spots[playerInput] = player;

        if (spots[0] == player && spots[1] == player && spots[2] == player ||
            spots[3] == player && spots[4] == player && spots[5] == player ||
            spots[6] == player && spots[7] == player && spots[8] == player ||

            spots[0] == player && spots[3] == player && spots[6] == player ||
            spots[1] == player && spots[4] == player && spots[7] == player ||
            spots[2] == player && spots[5] == player && spots[8] == player ||

            spots[0] == player && spots[4] == player && spots[8] == player ||
            spots[2] == player && spots[4] == player && spots[6] == player)
        {
            cout << player << " WINNER!" << endl;
            return true;
        }
        return false;
    }
    else cout << "Spot taken. Please take another one." << endl;
    return false;
}

void displaySpots(string spots[9]) {
    cout << spots[0] << " " << spots[1] << " " << spots[2] << endl;
    cout << spots[3] << " " << spots[4] << " " << spots[5] << endl;
    cout << spots[6] << " " << spots[7] << " " << spots[8] << endl;
}

int main() {
    string playerOne = "X";
    string playerTwo = "O";
    bool isPlayerOneTurn = true;
    bool gameOver = false;

    string spots[9] = { "?", "?", "?", "?", "?", "?", "?", "?", "?" };

    std::cout << "TicTacToe is ready to be played!\n";

    while (!gameOver) {
        displaySpots(spots);

        switch (isPlayerOneTurn) {
        case true:
            gameOver = playerTurn(playerOne, spots);
            break;
        case false:
            gameOver = playerTurn(playerTwo, spots);
            break;
        }
        if (!freeSpots(spots)) {
            cout << "It is a DRAW!" << endl;
            break;
        }
        isPlayerOneTurn = !isPlayerOneTurn;
    }
    displaySpots(spots);
    cout << "GAME OVER" << endl;
}
