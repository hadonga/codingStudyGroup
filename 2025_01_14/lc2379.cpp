#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int minimumRecolors(string blocks, int k){
        int ans = 0;
        int cnt = 0;
        // init
        for (int i = 0; i < k; ++i){
            if (blocks[i] == 'W') cnt += 1; 
        }
        // in and out
        ans = cnt;
        for (int i = k; i < blocks.size(); ++i){
            if(blocks[i - k] == 'W') cnt -= 1;
            if(blocks[i] == 'W') cnt += 1;
            ans = min(ans, cnt);
        }
        return ans;
    }

};

int main(){

    string blocks = "WBBWWBBWBW";
    int k = 7;

    return 0;
}