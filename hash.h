#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

//hashing function
uint32_t com_hash(const string& msg) {
    uint32_t hash = 0;
    uint32_t p = 31;

    for (size_t i = 0; i < msg.length(); i++) {
        uint32_t pos = msg[i] % 32;
        hash = (hash * p) + pos;
        hash ^= (hash << 5);
        hash ^= (hash >> 3);
    }
    return hash;
}

//coverting numeric to alpha
string HtoA(uint32_t hash) {
    string num = to_string(hash);
    string result = "";

    for (char c : num) {
        result += ('A' + (c - '0'));
    }

    return result;
}

#endif