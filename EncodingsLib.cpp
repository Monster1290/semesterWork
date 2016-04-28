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
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            s[i] += key;
            if (s[i] > 'Z') s[i] += -'Z' + 'A' - 1;
            if (s[i] < 'A') s[i] += -'A' + 'Z' + 1;
        }
    }
    return s;
}

string Encoding::VigenereEncrypt(string s, string key) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    unsigned int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            s[i] += key[j] - 'A';
            if (s[i] > 'Z') s[i] += -'Z' + 'A' - 1;
        }
        j = j + 1 == key.length() ? 0 : j + 1;
    }
    return s;
}