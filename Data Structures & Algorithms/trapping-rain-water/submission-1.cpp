class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() - 1;

        int left = 0;
        int right = n;
        int leftMax = height[left];
        int rightMax = height[right];
        int total = 0;

        while(left < right) {
            //處理左邊
            if(leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                total += (leftMax - height[left]);
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                total += (rightMax - height[right]);
            }
        }

        return total;
    }
};
