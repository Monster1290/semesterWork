//
//  EncodingsLib.cpp
//  exampleC++
//
//  Created by Александр on 24.04.16.
//  Copyright © 2016 Alexander Besedin. All rights reserved.
//

#include "EncodingsLib.hpp"
#include <stdexcept>

using namespace std;

string Encoding::CaesarEncrypt(string s, unsigned short int key)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            uint16_t newSymbol = s[i] + key;
            if (s[i] <= 'Z' && s[i] >= 'A') {
                if (newSymbol > 'Z') newSymbol += -'Z' + 'A' - 1;
                if (newSymbol < 'A') newSymbol += -'A' + 'Z' + 1;
            }
            if (s[i] <= 'z' && s[i] >= 'a') {
                if (newSymbol > 'z') newSymbol += -'z' + 'a' - 1;
                if (newSymbol < 'a') newSymbol += -'a' + 'z' + 1;
            }
            s[i] = newSymbol;
        }
    }
    return s;
}

string Encoding::VigenereEncrypt(string s, string key) {
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    unsigned int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            int16_t newSymbol = s[i];
            if (newSymbol <= 'Z' && newSymbol >= 'A') {
                newSymbol += toupper(key[j]) - 'A';
                if (newSymbol > 'Z') newSymbol += -'Z' + 'A' - 1;
            }
            if (newSymbol <= 'z' && newSymbol >= 'a') {
                newSymbol += key[j] - 'a';
                if (newSymbol > 'z') newSymbol += -'z' + 'a' - 1;
            }
            s[i] = newSymbol;
        }
        j = j + 1 == key.length() ? 0 : j + 1;
    }
    return s;
}