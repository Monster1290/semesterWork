//
//  EncodingsLib.hpp
//  exampleC++
//
//  Created by Александр on 24.04.16.
//  Copyright © 2016 Alexander Besedin. All rights reserved.
//

#ifndef EncodingsLib_hpp
#define EncodingsLib_hpp

#include <stdio.h>
#include <string>

#endif /* EncodingsLib_hpp */

using namespace std;

class Encoding {
public:
    static string CaesarEncrypt(string s, unsigned short int key);
};