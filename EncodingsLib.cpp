//
//  EncodingsLib.cpp
//  exampleC++
//
//  Created by Александр on 24.04.16.
//  Copyright © 2016 Alexander Besedin. All rights reserved.
//

#include "EncodingsLib.hpp"
#include <stdexcept>
#include <algorithm>
#include <locale>

using namespace std;

string Encoding::CaesarEncrypt(string s, unsigned short int key)
{
   unsigned char newEnglishSymbol; //т.к. char только положительные
   char newRussianSymbol; //т.к. char могут быть и отрицательными
   for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {          //если символ - буква
			if (((s[i] >= 'A') && (s[i] <= 'Z'))||((s[i] >= 'a') && (s[i] <= 'z'))){ //английский язык
				while ((key>27)||(key<-27)){  
					if (key>27) key=key-26;
					if (key<-27) key=key+26;
				}
				newEnglishSymbol = s[i] + key;
				if ((s[i] >= 'a') && (s[i] <= 'z')) {
					if (newEnglishSymbol > 'z')  newEnglishSymbol += -'z' + 'a' - 1; 
					 if (newEnglishSymbol < 'a')  newEnglishSymbol += -'a' + 'z' + 1; 
				 }
				if ((s[i] >= 'A') && (s[i] <= 'Z')) {
					if (newEnglishSymbol > 'Z') newEnglishSymbol += -'Z' + 'A' - 1;
					if (newEnglishSymbol < 'A') newEnglishSymbol += -'A' + 'Z' + 1;
				}
				s[i] = newEnglishSymbol;
			}
			if (((s[i] >= 'А') && (s[i] <= 'Я'))||((s[i] >= 'а') && (s[i] <= 'я'))){   //русский язык
				while ((key>33)||(key<-33)){
					if (key>33) key=key-32;
					if (key<-33) key=key+32;
				}
				newRussianSymbol = s[i] + key;
				if ((s[i] >= 'А') && (s[i] <= 'Я')) {
					if (newRussianSymbol > 'Я') newRussianSymbol += -'Я' + 'А' - 1;
					if (newRussianSymbol < 'А') newRussianSymbol += -'А' + 'Я' + 1;
				}
				if ((s[i] >= 'а') && (s[i] <= 'я')) {
					if (newRussianSymbol > 'я') newRussianSymbol+= -'я' + 'а' - 1;
					if (newRussianSymbol < 'а') newRussianSymbol += -'а' + 'я' + 1;
				}	
				s[i] = newRussianSymbol;
			}
		}
	}
    return s;
}

string Encoding::VigenereEncrypt(string s, string key) {
    locale loc("Russian");
	transform(key.begin(), key.end(), key.begin(), ::tolower);
    unsigned int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha((s[i]),loc))
        {
            if (((s[i] >= 'A') && (s[i] <= 'Z'))||((s[i] >= 'a') && (s[i] <= 'z'))){
				char newEnglishSymbol = s[i];
				if ((newEnglishSymbol >= 'A') && (newEnglishSymbol <= 'Z')) {
					newEnglishSymbol += toupper(key[j]) - 'A';
					if (newEnglishSymbol > 'Z') newEnglishSymbol += -'Z' + 'A' - 1;
				}
				if ((newEnglishSymbol >= 'a') && (newEnglishSymbol <= 'z')) {
				  newEnglishSymbol += key[j] - 'a';
				  if (newEnglishSymbol > 'z')newEnglishSymbol += -'z' + 'a' - 1;
				}
				s[i] = newEnglishSymbol;
			}
			if (((s[i] >= 'А') && (s[i] <= 'Я'))||((s[i] >= 'а') && (s[i] <= 'я'))){
				unsigned char newRussianSymbol=s[i];
				if ((newRussianSymbol >= 'А') && (newRussianSymbol <= 'Я')) {
					 newRussianSymbol += toupper(key[j]) - 'А';
					 if (newRussianSymbol > 'Я') newRussianSymbol += -'Я' + 'А' - 1;
				}
				if ((newRussianSymbol >= 'а') && (newRussianSymbol <= 'я')) {
					newRussianSymbol += key[j] - 'а';
					if (newRussianSymbol > 'я') newRussianSymbol += -'я' + 'а' - 1;
				}
				s[i] = newRussianSymbol;
			}
        }
        j = j + 1 == key.length() ? 0 : j + 1;
    }
    return s;
}