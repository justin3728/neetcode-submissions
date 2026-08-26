class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        for(char c : s1) {
            mp[c]++;
        }

        int left = 0;
        
        for(int right = 0; right < s2.size(); right++) {
            mp[s2[right]]--;
            
            while(mp[s2[right]] < 0) {
                mp[s2[left]]++;
                left++;
            }

            if(right - left == s1.size() - 1) return true;
        }

        return false;
    }
};
