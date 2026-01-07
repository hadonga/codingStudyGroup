#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> count(string &str) {
    vector<int> cnt(26, 0);
    for (auto ch: str) {
        cnt[ch - 'a'] += 1;
    }
    return cnt;
}

bool equalvec(vector<int> &vec1, vector<int> vec2) {
    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] != vec2[i]) return false;
    }
    return true;
}

string ArrayChallenge(string str) {
    str += ' ';

    unordered_map<string, unordered_set<string>> table;
    unordered_map<string, vector<int>> cnts;
    int start = 0, n = str.size();
    for (int i = 0; i < n; ++i) {
        char ch = str[i];
        if (ch != ' ') {
            continue;
        }
        else if (start == i) {
            start = i + 1;
            continue;
        }

        string sub_new = str.substr(start, i-start);
        vector<int> cnt_new = count(sub_new);
        bool find = false;
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            auto sub = it->first;

            auto cnt = it->second;
            if (sub_new.size() == sub.size() && sub_new != sub && equalvec(cnt_new, cnt)) {
                table[sub].insert(sub_new);
                find = true;
                break;
            }
        }
        if (!find) {
            table[sub_new] = {};
            cnts[sub_new] = cnt_new;
        }

        start = i + 1;
    }

    int res = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        res += it->second.size();
    }
    return to_string(res);
}

int main() {
    string str = "  aa aa  odg dog god";
    // string str = "a o b o run urn urn";
    cout << ArrayChallenge(str) << '\n';
    return 0;
}