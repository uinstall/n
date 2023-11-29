#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    char continueChoice;

    do {
        cout << "Choose a program to run:" << endl;
        cout << "1. Parity Check" << endl;
        cout << "2. Hamming Code" << endl;
        cout << "3. CRC" << endl;
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string data;
                char parity;
                int ones = 0, zeros = 0;

                cout << "Enter Data Bits (in Binary) : ";
                cin >> data;

                for (int i = 0; i < data.length(); i++) {
                    if (data[i] == '1') {
                        ones++;
                    }
                    if (data[i] == '0') {
                        zeros++;
                    }
                }

                if (ones % 2 == 0) {
                    parity = '0';
                } else {
                    parity = '1';
                }

                data = data + parity;

                cout << "Data after Parity Bit Adding : " << data;
                break;
            }
            case 2: {
                int dataBits[4];
                int encodedBits[7];

                cout << "Enter 4 Data Bits (0 or 1): ";
                for (int i = 0; i < 4; ++i) {
                    cin >> dataBits[i];
                }

                encodedBits[2] = dataBits[0];
                encodedBits[4] = dataBits[1];
                encodedBits[5] = dataBits[2];
                encodedBits[6] = dataBits[3];

                encodedBits[0] = encodedBits[2] ^ encodedBits[4] ^ encodedBits[6];
                encodedBits[1] = encodedBits[2] ^ encodedBits[5] ^ encodedBits[6];
                encodedBits[3] = encodedBits[4] ^ encodedBits[5] ^ encodedBits[6];

                cout << "Encoded Bits: ";
                for (int i = 0; i < 7; ++i) {
                    cout << encodedBits[i] << " ";
                }
                break;
            }
            case 3: {
                string input, divisor;

                cout << "Enter Data (in binary): ";
                cin >> input;

                cout << "Enter Divisor (in binary): ";
                cin >> divisor;

                int inputLength = input.length();
                int divisorLength = divisor.length();

                input += string(divisorLength - 1, '0');

                for (int i = 0; i < inputLength; ++i) {
                    if (input[i] == '1') {
                        for (int j = 0; j < divisorLength; ++j) {
                            input[i + j] = (input[i + j] == divisor[j]) ? '0' : '1';
                        }
                    }
                }

                string crcCode = input.substr(inputLength, divisorLength - 1);
                cout << "Generated CRC Code: " << crcCode << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
