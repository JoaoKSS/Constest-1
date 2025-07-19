#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string joinLines(const vector<string>& lines){
    if(lines.empty()) return "";
    string result = lines[0];
    for (size_t i = 1; i < lines.size(); i++){
        result += "\n" + lines[i];
    }
    return result;
}

string extractDigits(const vector<string>& lines){
    string digits;
    for (const string &line : lines){
        for (char c : line){
            if(isdigit(c)){
                digits.push_back(c);
            }
        }
    }
    return digits;
}

int main(){
    int n, m;
    int run = 1;
    
    while(cin >> n && n != 0) {
        cin.ignore(); 
        
        vector<string> standardSolution(n);
        for (int i = 0; i < n; i++){
            getline(cin, standardSolution[i]);
        }
        
        cin >> m;
        cin.ignore();
        vector<string> teamOutput(m);
        for (int i = 0; i < m; i++){
            getline(cin, teamOutput[i]);
        }
        
        string stdStr = joinLines(standardSolution);
        string teamStr = joinLines(teamOutput);
        
        cout << "Run #" << run++ << ": ";
        
        if (stdStr == teamStr) {
            cout << "Accepted" << endl;
        } else {
            string stdDigits = extractDigits(standardSolution);
            string teamDigits = extractDigits(teamOutput);
            if (stdDigits == teamDigits)
                cout << "Presentation Error" << endl;
            else
                cout << "Wrong Answer" << endl;
        }
    }
    
    return 0;
}
