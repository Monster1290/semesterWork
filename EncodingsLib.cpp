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
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
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