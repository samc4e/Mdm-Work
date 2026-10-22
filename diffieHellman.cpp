
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Public parameters
    int p = 23, g = 5;

    // Private keys of Alice and Bob
    int a = 6, b = 15;

    // Calculate public keys
    int A = 1, B = 1;

    for (int i = 0; i < a; i++)
        A = (A * g) % p;

    for (int i = 0; i < b; i++)
        B = (B * g) % p;

    cout << "Alice's Public Key: " << A << endl;
    cout << "Bob's Public Key: " << B << endl;

    // Calculate shared secret keys
    int keyA = 1, keyB = 1;

    for (int i = 0; i < a; i++)
        keyA = (keyA * B) % p;

    for (int i = 0; i < b; i++)
        keyB = (keyB * A) % p;

    cout << "Alice's Shared Secret Key: " << keyA << endl;
    cout << "Bob's Shared Secret Key: " << keyB << endl;

    if (keyA == keyB)
        cout << "Key Exchange Successful!" << endl;
    else
        cout << "Key Exchange Failed!" << endl;

    return 0;
}
