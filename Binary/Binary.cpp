// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int bitNumber = 32;
int bits[bitNumber];

void displayBinary(unsigned input) {
    int i = 0;

    while (input > 0) {
        bits[i] = input % 2;
        input /= 2;
        i++;
    }

    cout << "0b";
    int numberOfBlocks = 4;

    for (int number = bitNumber - 1; number >= 0; number--) {
        cout << bits[number];
        --numberOfBlocks;
        if (numberOfBlocks == 0) {
            cout << " ";
            numberOfBlocks = 4;
        }
    }

    cout << endl;
}


int main() {
    cout << "Binary converter ready!\nOnly positive numbers can be converted." << endl;

    while (true) {
        cout << "-Type a number to convert it to binary:" << endl;
        unsigned input;
        cin >> input;
        if (input < 0) {
            cout << input << "is a negative number and it is not supported yet." << endl;
        }
        else {
            cout << "-Type 1 to confirm:" << endl;
            int selectedOption;
            cin >> selectedOption;
            if (selectedOption == 1){ 
                cout << "The number you typed in binary is: " << endl;
                displayBinary(input);
            }
        }
    }
}
