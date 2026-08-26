class Solution {
public:
    string minWindow(string s, string t) {
        int missing = t.size();
        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }

        int left = 0;
        int start = 0;
        int minLength = INT_MAX;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];

            if(mp[c] > 0) {
                missing--;
            }

            mp[c]--;

            while(missing == 0) {
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;
                
                if(mp[s[left]] > 0) {
                    missing++;
                }

                left++;
            }
        }

        return minLength ==  INT_MAX ? "" : s.substr(start, minLength);

    }
};
