#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string keyboard = "`1234567890-=" "QWERTYUIOP[]\\" "ASDFGHJKL;'" "ZXCVBNM,./";
    
    unordered_map<char, char> decode;
    for (size_t i = 1; i < keyboard.size(); i++)
        decode[keyboard[i]] = keyboard[i - 1];
    
    string line;
    while(getline(cin, line)){
        for (char c : line){
            if (decode.find(c) != decode.end())
                cout << decode[c];
            else
                cout << c;
        }
        cout << "\n"; 
    }
    
    return 0;
}
