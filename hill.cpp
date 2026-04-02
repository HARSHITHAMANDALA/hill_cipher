#include <iostream>
#include <string>
#include <vector>
#include "hill.h"
#include "hash.h"

using namespace std;

string rmv_pad(const string& text) {
    string res = text;
    while (!res.empty() && res.back() == 'X') {
        res.pop_back();
    }
    return res;
}

int main() {
    string msg;
    cout << "Enter message: ";
    cin >> msg;

    vector<vector<int>> key(3, vector<int>(3));
    cout << "Enter 9 values:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> key[i][j];

    //Hashing
    uint32_t hash = com_hash(msg);
    string alphaHash = HtoA(hash);

    //Combining msg and non numeric hash
    string combined = msg + alphaHash;
    cout << "Combined: " << combined << endl;

    // encryption
    string enc = encryption(combined, key);
    cout << "encrypted: " << enc << endl;

    //Decryption
    string dyc = decryption(enc, key);
    dyc = rmv_pad(dyc);
    cout << "decrypted: " << dyc << endl;

    //spliting
    int hashLen = alphaHash.length();
    string original = dyc.substr(0, dyc.length() - hashLen);
    string eh = dyc.substr(dyc.length() - hashLen);

    cout << "Original: " << original << endl;
    cout << "Extracted Hash: " << eh << endl;

    //verify
    uint32_t newh = com_hash(original);
    string newah = HtoA(newh);

    if (newah == eh)
        cout << "Integrity Verified\n";
    else
        cout << "Integrity Failed\n";

    return 0;
}