#include <iostream>
#include <iomanip>
#include <map>
#include <string>

//using namespace std;


std::string CaesarEncrypt(std::string s, unsigned short int key) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char newSymbol = s[i] - key;
            s[i] = newSymbol;
        }
    }
    return s;
}

std::string VigenereEncrypt(std::string s, std::string key)
{
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
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

int main () {
    std::string example = "How are you? Can you help me with my homework?";
    std::cout << CaesarEncrypt(example, 4) << std::endl;
    std::cout << VigenereEncrypt(example, "Meow") << std::endl;
    return 0;
}