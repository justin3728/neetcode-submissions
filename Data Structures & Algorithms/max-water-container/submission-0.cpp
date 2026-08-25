class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int ans = 0;

        while(left < right) {
            int curArea = (right - left) * min(heights[left], heights[right]);
            
            if(curArea > ans) {
                ans = curArea;
            }
            
            if(heights[left] > heights[right]) {
                right--;
            }
            else {
                left++;
            }
        }

        return ans;
    }
};
