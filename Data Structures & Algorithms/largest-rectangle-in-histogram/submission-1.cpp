class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //H, idx
        stack<pair<int, int>> st;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push({heights[i], i});
            }
            else {
                int start = i;

                while(!st.empty() && heights[i] < st.top().first) {
                    ans = max(ans, st.top().first * (i - st.top().second));
                    start = st.top().second;
                    st.pop();
                }
                st.push({heights[i], start});
            }
        }

        while(!st.empty()) {
            ans = max(ans, st.top().first * (n - st.top().second));
            st.pop();
        }

        return ans;
    }
};
