class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> st;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            
            while(st.count(c)) {
                st.erase(s[left]);
                left++;
            }

            st.insert(c);

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
