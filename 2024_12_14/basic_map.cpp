#include <iostream>

#include <unordered_map>
#include <map>
#include <string>

using namespace std;

int main() {
    unordered_map<int, string> unordered = {
        {100, "val_100"},
        {200, "val_200"}
    };
    unordered[1] = "val_1";
    unordered[100] = "val_100_new";

    // 映射写法
    for (auto iter = unordered.begin(); iter != unordered.end(); ++iter) {
        cout << iter->first << ": " << iter->second << '\n';
    }

    if (unordered.find(100) != unordered.end()) cout << "key exists\n";
    else cout << "key does not exist\n";

    map<string, int> dict = {
        {"val_2000", 1000},
        {"val_1000", 2000}
    };

    for (auto iter = dict.begin(); iter != dict.end(); ++iter){
        cout << iter->first << ": " << iter->second << '\n';
    }

    return 0;
}