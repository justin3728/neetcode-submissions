class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int current = nums[i];
            int need = target - current;
            
            if(mp.count(need)) {
                return {mp[need], i};
            }
            else {
                mp[current] = i;
            }
        }

        return {};

    }
};
