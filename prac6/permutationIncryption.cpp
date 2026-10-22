#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generic permutation function
string permutation(const string& input,
                   const vector<int>& table) {
    string output;

    for (int position : table) {
        output += input[position - 1];
    }

    return output;
}

int main() {

    // -------------------------------
    // 1. Straight Permutation
    // -------------------------------

    string input1 = "1011";

    vector<int> straightTable = {
        2, 4, 1, 3
    };

    string straightOutput =
        permutation(input1, straightTable);

    cout << "Straight Permutation\n";
    cout << "Input  : " << input1 << endl;
    cout << "Output : " << straightOutput << endl;


    // -------------------------------
    // 2. Expansion Permutation
    // -------------------------------

    string input2 = "1011";

    vector<int> expansionTable = {
        1, 2, 3, 2, 3, 4
    };

    string expansionOutput =
        permutation(input2, expansionTable);

    cout << "\nExpansion Permutation\n";
    cout << "Input  : " << input2 << endl;
    cout << "Output : " << expansionOutput << endl;


    // -------------------------------
    // 3. Compression Permutation
    // -------------------------------

    string input3 = "101101";

    vector<int> compressionTable = {
        1, 3, 5, 6
    };

    string compressionOutput =
        permutation(input3, compressionTable);

    cout << "\nCompression Permutation\n";
    cout << "Input  : " << input3 << endl;
    cout << "Output : " << compressionOutput << endl;

    return 0;
}