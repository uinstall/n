/* PRACTICAL 4
NAME : Kaveri Zanzane
PRN : 202202040023
Write a program to implement sliding window mechanisms using

1. Stop and Wait ARQ 
2. Go Back N ARQ 
3. Selective Repeat ARQ*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate Stop and Wait ARQ
void stopAndWaitARQ() {
    int totalFrames;
    cout << "Enter total number of frames to be sent: ";
    cin >> totalFrames;

    vector<int> senderBuffer(totalFrames);
    vector<int> receiverBuffer;
    
    for (int frame = 1; frame <= totalFrames; ++frame) {
        cout << "Sender sending frame " << frame << endl;

        // Simulate frame loss with a 20% probability
        if (rand() % 5 != 0) {
            cout << "Receiver received frame " << frame << endl;
            receiverBuffer.push_back(frame);
            cout << "Receiver sending ACK for frame " << frame << endl;
        } else {
            cout << "Frame lost!" << endl;
        }
    }
}

// Function to simulate Go Back N ARQ
void goBackNARQ() {
    int windowSize, totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;
    cout << "Enter total number of frames to be sent: ";
    cin >> totalFrames;

    vector<int> senderBuffer(totalFrames);
    vector<int> receiverBuffer;
    
    for (int frame = 1; frame <= totalFrames; ++frame) {
        cout << "Sender sending frame " << frame << endl;

        // Simulate frame loss with a 20% probability
        if (rand() % 5 != 0) {
            cout << "Receiver received frame " << frame << endl;
            receiverBuffer.push_back(frame);
        } else {
            cout << "Frame lost!" << endl;
        }

        // Send ACKs for frames in the window
        while (!receiverBuffer.empty() && receiverBuffer[0] <= frame - windowSize) {
            cout << "Receiver sending ACK for frame " << receiverBuffer[0] << endl;
            receiverBuffer.erase(receiverBuffer.begin());
        }
    }
}

// Function to simulate Selective Repeat ARQ
void selectiveRepeatARQ() {
    int windowSize, totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;
    cout << "Enter total number of frames to be sent: ";
    cin >> totalFrames;

    vector<int> senderBuffer(totalFrames);
    vector<int> receiverBuffer(totalFrames, 0);
    
    for (int frame = 1; frame <= totalFrames; ++frame) {
        cout << "Sender sending frame " << frame << endl;

        // Simulate frame loss with a 20% probability
        if (rand() % 5 != 0) {
            cout << "Receiver received frame " << frame << endl;
            receiverBuffer[frame - 1] = frame;
        } else {
            cout << "Frame lost!" << endl;
        }
        
        // Send ACK for received frame
        cout << "Receiver sending ACK for frame " << frame << endl;

        // Send ACKs for frames in the window
        for (int i = 0; i < windowSize && frame + i <= totalFrames; ++i) {
            if (receiverBuffer[frame + i - 1] != 0) {
                cout << "Receiver sending ACK for frame " << receiverBuffer[frame + i - 1] << endl;
            }
        }
    }
}

int main() {
    srand(time(0));  // Seed the random number generator

    while (true) {
        cout << "\nChoose ARQ Protocol:" << endl;
        cout << "1. Stop and Wait ARQ" << endl;
        cout << "2. Go Back N ARQ" << endl;
        cout << "3. Selective Repeat ARQ" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stopAndWaitARQ();
                break;
            case 2:
                goBackNARQ();
                break;
            case 3:
                selectiveRepeatARQ();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
