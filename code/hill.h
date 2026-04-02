#ifndef HILL_H
#define HILL_H

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

inline int char_num(char c) {
    return toupper(c) - 'A';
}

inline char num_char(int n) {
    return 'A'+ n;
}

int mod_inv(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a*x)%m == 1)
            return x;
    }
    return -1;
}

// Encryption
string encryption(string msg, const vector<vector<int>>& key) {
    for (char &c : msg) c = toupper(c);

    while (msg.length() % 3 != 0) msg += 'X';

    string en_text = "";

    for (int i = 0; i < msg.length(); i += 3) {
        int temp[3];
        for (int j = 0; j < 3; j++)
            temp[j] = char_num(msg[i+j]);

        for (int r = 0; r < 3; r++) {
            int sum = 0;
            for (int k = 0; k < 3; k++)
                sum += key[r][k] * temp[k];

            en_text += num_char((sum % 26 + 26) % 26);
        }
    }
    return en_text;
}

// Adjoint
vector<vector<int>> adjoint(const vector<vector<int>>& key) {
    vector<vector<int>> adj(3, vector<int>(3));

    // Cofactor matrix
    adj[0][0] =  (key[1][1]*key[2][2] - key[1][2]*key[2][1]);
    adj[0][1] = -(key[1][0]*key[2][2] - key[1][2]*key[2][0]);
    adj[0][2] =  (key[1][0]*key[2][1] - key[1][1]*key[2][0]);

    adj[1][0] = -(key[0][1]*key[2][2] - key[0][2]*key[2][1]);
    adj[1][1] =  (key[0][0]*key[2][2] - key[0][2]*key[2][0]);
    adj[1][2] = -(key[0][0]*key[2][1] - key[0][1]*key[2][0]);

    adj[2][0] =  (key[0][1]*key[1][2] - key[0][2]*key[1][1]);
    adj[2][1] = -(key[0][0]*key[1][2] - key[0][2]*key[1][0]);
    adj[2][2] =  (key[0][0]*key[1][1] - key[0][1]*key[1][0]);

    // Transpose
    vector<vector<int>> adjnt(3, vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            adjnt[i][j] = ((adj[j][i] % 26) + 26) % 26;
        }
    }

    return adjnt;
}

// Inverse key
vector<vector<int>> inv_key(const vector<vector<int>>& key) {
    int det =
        key[0][0]*(key[1][1]*key[2][2] -key[1][2]*key[2][1]) - key[0][1]*(key[1][0]*key[2][2]-key[1][2]*key[2][0]) + key[0][2]*(key[1][0]*key[2][1]-key[1][1]*key[2][0]);
    det = ((det % 26) + 26) % 26;   
    int inv_det = mod_inv(det, 26);

    if (inv_det == -1) {
        cerr << "Key not invertible!\n";
        exit(1);
    }

    vector<vector<int>> adj = adjoint(key);
    vector<vector<int>> inv(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inv[i][j] = (adj[i][j] * inv_det) % 26;

    return inv;
}

// Decryption
string decryption(string msg, const vector<vector<int>>& key) {
    vector<vector<int>> invKey = inv_key(key);
    string de_text = "";

    for (int i = 0; i < msg.length(); i += 3) {
        int temp[3];
        for (int j = 0; j < 3; j++)
            temp[j] = char_num(msg[i+j]);

        for (int r = 0; r < 3; r++) {
            int sum = 0;
            for (int k = 0; k < 3; k++)
                sum += invKey[r][k] * temp[k];

            de_text += num_char((sum % 26 + 26) % 26);
        }
    }
    return de_text;
}

#endif