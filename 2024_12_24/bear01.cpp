#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

bool valid(string &s, string &invalid) {
    for (int i = 0; i < 8; ++i) {
        if (tolower(s[i]) != invalid[i]) return true;
    }
    return false;
}
string StringChallenge(string &str) {
    string res = "false";
    int n = str.size();
    if (n <= 7 || n >= 31) return res;

    bool capital = false, number = false, special = false;
    string invalid = "password";
    unordered_set<char> mathsymbols {'+', '-', '*', '/', '<', '>', '='};
    for (int i = 0; i < n; ++i) {
        char ch = str[i];

        if (i + 7 < n && ch == 'p') {
            string sub = str.substr(i, 8);
            if (!valid(sub, invalid)) return res;
        }
        
        if (isupper(ch)) capital = true;
        else if (isdigit(ch)) number = true;
        else if (ispunct(ch) || (mathsymbols.find(ch) != mathsymbols.end())) special = true;
    }

    if (capital && number && special) res = "true";
    return res;
}

int main() {
    // string str = "passWord123!";
    string str = "turkey90AAA!";
    cout << StringChallenge(str) << '\n';

    return 0;
}