#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string key = "the quick brown fox jumps over the lazy dog";

bool Mapa(string &linha, map<char, char> &mapa){
    if(linha.size() != key.size())
        return false;
    
    mapa.clear(); 
    map<char, char> reverso;
    
    for (size_t i = 0; i < linha.size(); i++) {
        char c1 = linha[i];
        char c2 = key[i];
        
        if(c1 == ' ' && c2 != ' ')
            return false;
        if(c1 != ' ' && c2 == ' ')
            return false;
        
        if(c1 != ' ') {
            if(mapa.find(c1) != mapa.end()){
                if(mapa[c1] != c2)
                    return false;
            } else {
                if(reverso.find(c2) != reverso.end() && reverso[c2] != c1)
                    return false;
                mapa[c1] = c2;
                reverso[c2] = c1;
            }
        }
    }
    
    if(mapa.size() < 26) 
        return false;
    return true;
}

int main(){
    int T;
    cin >> T;
    cin.ignore(); 
    string linha;
    getline(cin, linha);

    for (int t = 0; t < T; t++){
        vector<string> entrada;
        
        while(getline(cin, linha)){
            if(linha.empty())
                break;
            entrada.push_back(linha);
        }
        
        map<char, char> mapa;
        bool encontrou = false;
        for(auto &s : entrada){
            if(Mapa(s, mapa)){
                encontrou = true;
                break;
            }
        }
        
        if(!encontrou){
            cout << "No solution." << endl;
        } else {
            for(auto &s : entrada){
                for(auto c : s){
                    if(c == ' ')
                        cout << ' ';
                    else
                        cout << mapa[c];
                }
                cout << endl;
            }
        }
        
        if(t < T - 1)
            cout << endl;
    }
    return 0;
}
