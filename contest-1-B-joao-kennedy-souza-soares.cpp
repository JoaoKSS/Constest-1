#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore(); 

    int dx[8] = { -1, -1, -1,  0, 0, 1, 1, 1 };
    int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    
    while(t--){
        int m, n;
        cin >> m >> n;
        cin.ignore();
        
        vector<string> grid(m);
        for (int i = 0; i < m; i++){
            getline(cin, grid[i]);
            transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::tolower);
        }
        
        int k;
        cin >> k;
        cin.ignore();  
        
        for (int p = 0; p < k; p++){
            string word;
            getline(cin, word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            bool found = false;
            
            for (int i = 0; i < m && !found; i++){
                for (int j = 0; j < n && !found; j++){
                    if (grid[i][j] == word[0]) {
                        for (int d = 0; d < 8 && !found; d++) {
                            int len = word.size();
                            int k_char;
                            for (k_char = 0; k_char < len; k_char++){
                                int nr = i + k_char * dx[d];
                                int nc = j + k_char * dy[d];
                                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != word[k_char])
                                    break;
                            }
                            if (k_char == len){
                                cout << (i + 1) << " " << (j + 1) << endl;
                                found = true;
                            }
                        }
                    }
                }
            }
        }
        
        if(t) cout << endl;  
    }
    return 0;
}
