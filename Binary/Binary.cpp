// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int bitsNumber = 32;
int bits[bitsNumber];

void convertToBinaryWithDivisionModulo(unsigned input) {
    int i = 0;

    while (input > 0) {
        bits[i] = input % 2;
        input /= 2;
        i++;
    }

    cout << "0b ";
    int numberOfBlocks = 4;
    for (int number = bitsNumber - 1; number >= 0; number--) {
        cout << bits[number];
        --numberOfBlocks;
        if (numberOfBlocks == 0) {
            cout << " ";
            numberOfBlocks = 4;
        }
    }

    cout << endl;
}

void convertToBinaryWithOperations(unsigned input) {
    cout << "0b ";
    int numberOfBlocks = 4;

    for (int i = bitsNumber - 1; i >= 0; i--)
    {
        int numberToConvert = input >> i;
        if (numberToConvert & 1) cout << "1";
        else cout << "0";
        --numberOfBlocks;
        if (numberOfBlocks == 0) {
            cout << " ";
            numberOfBlocks = 4;
        }
    }
    cout << endl;
}

int main() {
    cout << "Binary converter ready!\nNegative numbers are not supported.Please only type positive numbers." << endl;
    while (true)
    {
        cout << "Type the number you wish to convert to binary:" << endl;
        unsigned input;
        cin >> input;
        if (input < 0)
            cout << input << " is a negative number, therefore is not supported yet." << endl;
        else {
            cout << "You can choose to convert using the modulo/division method or the binary operation method.\n-Type 1 to convert the number using modulo and division method\n-Type 2 to convert using binary operation method." << endl;
            int selectedOption;
            cin >> selectedOption;
            if (selectedOption == 1) {
                cout << "- The number you typed in binary is: " << endl;
                convertToBinaryWithDivisionModulo(input);
            }
            if (selectedOption == 2) {
                cout << "- The number you typed in binary is: " << endl;
                convertToBinaryWithOperations(input);
            }
        }

    }
}

