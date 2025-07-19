#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool verificaCandidato(const string& candidato, const vector<string>& fragments){
    unordered_multiset<string> fragSet(fragments.begin(), fragments.end());

    while(!fragSet.empty()){
        string a = *fragSet.begin();
        fragSet.erase(fragSet.begin());

        size_t len = a.size();
        string b1 = candidato.substr(len);
        string b2 = candidato.substr(0, candidato.size() - len);

        auto it = fragSet.find(b1);
        if(it != fragSet.end()){
            fragSet.erase(it);
        } else{
            it = fragSet.find(b2);
            if(it != fragSet.end()){
                fragSet.erase(it);
            } else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int T;
    string line;

    getline(cin, line);
    T = stoi(line);
    getline(cin, line); 

    for(int t = 0; t < T; t++){
        vector<string> fragments;

        while(getline(cin, line)){
            if(line.empty()) break;
            fragments.push_back(line);
        }

        sort(fragments.begin(), fragments.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        string menor = fragments.front();
        string maior = fragments.back();
        string candidato1 = menor + maior;
        string candidato2 = maior + menor;
        string resposta;

        if(verificaCandidato(candidato1, fragments)){
            resposta = candidato1;
        } else{
            resposta = candidato2;
        }

        cout << resposta << endl;
        if (t < T - 1) 
            cout << endl;
    }

    return 0;
}
