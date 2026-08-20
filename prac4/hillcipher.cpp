#include <bits/stdc++.h>
using namespace std;

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int modInverse(int a) {
    a = mod26(a);

    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

vector<vector<int>> multiplyMatrix(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B
) {
    vector<vector<int>> C(2, vector<int>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            C[i][j] = mod26(C[i][j]);
        }
    }

    return C;
}

vector<vector<int>> inverseKey(const vector<vector<int>>& K) {
    int a = K[0][0];
    int b = K[0][1];
    int c = K[1][0];
    int d = K[1][1];

    int det = mod26(a * d - b * c);
    int invDet = modInverse(det);

    if (invDet == -1)
        return {};

    vector<vector<int>> inv(2, vector<int>(2));

    inv[0][0] = mod26(d * invDet);
    inv[0][1] = mod26(-b * invDet);
    inv[1][0] = mod26(-c * invDet);
    inv[1][1] = mod26(a * invDet);

    return inv;
}

string encrypt(string text, const vector<vector<int>>& K) {
    string result;

    for (char &ch : text)
        ch = toupper(ch);

    if (text.length() % 2 != 0)
        text += 'X';

    for (int i = 0; i < text.length(); i += 2) {
        int x = text[i] - 'A';
        int y = text[i + 1] - 'A';

        int c1 = mod26(K[0][0] * x + K[0][1] * y);
        int c2 = mod26(K[1][0] * x + K[1][1] * y);

        result += char(c1 + 'A');
        result += char(c2 + 'A');
    }

    return result;
}

string decrypt(string text, const vector<vector<int>>& K) {
    vector<vector<int>> invK = inverseKey(K);

    if (invK.empty()) {
        return "INVALID KEY";
    }

    string result;

    for (char ch : text)
        ch = toupper(ch);

    for (int i = 0; i < text.length(); i += 2) {
        int x = text[i] - 'A';
        int y = text[i + 1] - 'A';

        int p1 = mod26(invK[0][0] * x + invK[0][1] * y);
        int p2 = mod26(invK[1][0] * x + invK[1][1] * y);

        result += char(p1 + 'A');
        result += char(p2 + 'A');
    }

    return result;
}

// Cryptanalysis using two known plaintext-ciphertext pairs
vector<vector<int>> cryptanalysis(
    string p1, string p2,
    string c1, string c2
) {
    vector<vector<int>> P = {
        {p1[0] - 'A', p2[0] - 'A'},
        {p1[1] - 'A', p2[1] - 'A'}
    };

    vector<vector<int>> C = {
        {c1[0] - 'A', c2[0] - 'A'},
        {c1[1] - 'A', c2[1] - 'A'}
    };

    vector<vector<int>> Pinv = inverseKey(P);

    if (Pinv.empty())
        return {};

    return multiplyMatrix(C, Pinv);
}

int main() {
    vector<vector<int>> key = {
        {3, 3},
        {2, 5}
    };

    string plaintext;

    cout << "Enter plaintext: ";
    cin >> plaintext;

    int det = mod26(
        key[0][0] * key[1][1] -
        key[0][1] * key[1][0]
    );

    if (modInverse(det) == -1) {
        cout << "Invalid key matrix.\n";
        return 0;
    }

    string ciphertext = encrypt(plaintext, key);

    cout << "Encrypted text: " << ciphertext << endl;

    string decrypted = decrypt(ciphertext, key);

    cout << "Decrypted text: " << decrypted << endl;

    // Cryptanalysis demonstration
    // Known plaintext:
    // HI -> ciphertext TC
    // AT -> ciphertext FA

    vector<vector<int>> recovered =
        cryptanalysis("HI", "AT", "TC", "FA");

    if (!recovered.empty()) {
        cout << "\nRecovered Key Matrix:\n";

        for (auto row : recovered) {
            for (int x : row)
                cout << x << " ";
            cout << endl;
        }
    } else {
        cout << "\nCryptanalysis failed.\n";
    }

    return 0;
}