class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;

        for(int num : nums) {
            st.insert(num);
        }

        for(int num : st) {
            if(st.count(num - 1)) continue;
            
            int length = 1;
            while(st.count(num + 1)) {
                length++;
                num++;
            }

            if(length > ans) ans = length;
        }

        return ans;
    }
};
