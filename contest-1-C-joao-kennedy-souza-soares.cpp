#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    while(getline(cin, a)){  
        if(!getline(cin, b)) 
            break;  

        int freqA[26] = {0};
        int freqB[26] = {0};

        for(auto c : a){
            if(isalpha(c)) 
                freqA[c - 'a']++;
        }

        for(auto c : b){
            if(isalpha(c)) 
                freqB[c - 'a']++;
        }

        string resultado = "";
        for(int i = 0; i < 26; i++) {
            int comum = min(freqA[i], freqB[i]);
            resultado.append(comum, 'a' + i);
        }
        cout << resultado << endl;
    }
    return 0;
}
