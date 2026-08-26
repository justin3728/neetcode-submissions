class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        unordered_map<char, int> mp;
        
        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            mp[c]++;
            maxFreq = max(maxFreq, mp[c]);

            while((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

        }

        return ans;
    }
};
