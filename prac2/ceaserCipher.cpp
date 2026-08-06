#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int key) {
    key = key % 26;

    for (char &ch : text) {
        if (ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' + key) % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' + key) % 26 + 'a';
    }
    return text;
}
string decrypt(string text, int key) {
    key = key % 26;

    for (char &ch : text) {
        if (ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' - key + 26) % 26 + 'a';
    }
    return text;
}

int main() {

    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "        CAESAR CIPHER PROGRAM\n";
        cout << "=========================================\n";
        cout << "1. Encrypt Message\n";
        cout << "2. Decrypt Message\n";
        cout << "3. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2) {
            string text;
            int key;

            cout << "\nEnter the message: ";
            getline(cin, text);

            cout << "Enter the key (Shift Value): ";
            cin >> key;

            if (choice == 1) {
                cout << "\nOriginal Message  : " << text << endl;
                cout << "Encrypted Message: " << encrypt(text, key) << endl;
            }
            else {
                cout << "\nEncrypted Message: " << text << endl;
                cout << "Decrypted Message: " << decrypt(text, key) << endl;
            }
        }
        else if (choice == 3) {
            cout << "\nThank you for using Caesar Cipher Program!\n";
        }
        else {
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}