class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();   
        vector<vector<int>> ans;

        for(int i = 0; i < n; i ++) {
            //剪枝
            if(nums[i] > 0) break;
            
            if(i != 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                if(sum == 0) {
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
                else if (sum < 0) {
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
