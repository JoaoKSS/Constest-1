#include <iostream>
#include <vector>
using namespace std;

static string trim_spaces(const string &s) {
    size_t start = s.find_first_not_of(' ');
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(' ');
    return s.substr(start, end - start + 1);
}

static vector<string> tokenize(const string &s) {
    vector<string> toks;
    int n = s.size();
    for (int i = 0; i < n; ) {
        if (s[i] == ' ') {
            int j = i;
            while (j < n && s[j] == ' ') j++;
            toks.push_back(s.substr(i, j - i));
            i = j;
        } else {
            int j = i;
            while (j < n && s[j] != ' ') j++;
            toks.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return toks;
}

static void format_paragraph(const vector<string> &block) {
    const string &first = block[0];
    int indent = 0;
    while (indent < (int)first.size() && first[indent] == ' ')
        indent++;
    string indent_str(indent, ' ');

    string text;
    for (size_t i = 0; i < block.size(); i++) {
        string line = block[i];
        while (!line.empty() && line.back() == ' ')
            line.pop_back();
        if (i == 0 && indent > 0)
            line = line.substr(indent);
        if (!text.empty())
            text += ' ';
        text += line;
    }

    if (block.size() == 1) {
        string only = first;
        while (!only.empty() && only.back() == ' ')
            only.pop_back();
        cout << only << "\n";
        return;
    }

    auto toks = tokenize(text);

    vector<string> out;
    string cur = indent_str;
    int cur_len = indent;  

    for (auto &tok : toks) {
        bool is_space = (tok[0] == ' ');
        int L = tok.size();

        if (is_space) {
            if (cur_len == 0) continue;
            if (cur_len + L <= 72) {
                cur += tok;
                cur_len += L;
            }
        } else {
            if (cur_len + L <= 72) {
                cur += tok;
                cur_len += L;
            } else if (L > 72) {
                if (cur_len > 0) {
                    out.push_back(cur);
                    cur.clear();
                    cur_len = 0;
                }
                out.push_back(tok);
            } else {
                if (cur_len > 0) {
                    out.push_back(cur);
                }
                cur = tok;
                cur_len = L;
            }
        }
    }
    if (!cur.empty()) {
        out.push_back(cur);
    }

    for (auto &l : out) {
        int e = (int)l.size() - 1;
        while (e >= 0 && l[e] == ' ') e--;
        cout << l.substr(0, e+1) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        lines.push_back(line);
    }

    int n = lines.size();
    for (int i = 0; i < n; ) {
        if (lines[i].find_first_not_of(' ') == string::npos) {
            cout << "\n";
            i++;
        } else {
            vector<string> block;
            block.push_back(lines[i++]);             
            while (i < n && lines[i].find_first_not_of(' ') != string::npos &&  
                lines[i][0] != ' ') {                            
                block.push_back(lines[i++]);
            }
            format_paragraph(block);
        }
    }

    return 0;
}
