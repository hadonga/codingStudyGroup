class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;   
        for (int i = 0; i < s.length(); ++i){
            // 1. in window
            if (s[i] == 'a' || s[i] =='e' || s[i] == 'i' || s[i] =='o' || s[i] == 'u') {
                    vowel +=1;
                }
                
            if (i < k - 1) {
                continue;
                }
            
            // 2. update
            ans = max(ans, vowel);
            
            // 3. out window
            char out = s[i - k + 1];
            if (out == 'a' || out =='e' || out == 'i' || out =='o' ||out == 'u') {
                vowel -=1;
                }
        }
    return ans;
    }
};