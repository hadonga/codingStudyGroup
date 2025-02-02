#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += (blocks[i] == 'W');
        }
        int res = cnt;
        for (int i = k; i < blocks.size(); ++i) {
            cnt += (blocks[i] == 'W');
            cnt -= (blocks[i-k] == 'W');
            res = min(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string blocks = "WBBWWBBWBW";
    int k = 7;
    cout << sol.minimumRecolors(blocks, k) << '\n';
    return 0;
}



