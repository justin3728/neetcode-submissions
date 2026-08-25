class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++) {
            prefix *= nums[i-1];
            ans[i] = prefix;
        }

        for(int i = n - 2; i >= 0; i--) {
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }
};
