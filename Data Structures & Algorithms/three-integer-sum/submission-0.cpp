class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i ++) {
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            if(i != 0 && nums[i] == nums[i - 1]) continue;

            while(left < right) {
                
                if(nums[left] + nums[right] == target) {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
            
        }

        return ans;
    }
};
