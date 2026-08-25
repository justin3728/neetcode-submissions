class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        int n = nums.size();

        //bucket(count, nums)
        vector<vector<int>> bucket(n + 1);
        
        //轉array之後sort
        for(auto& [key, value] : mp) {
            bucket[value].push_back(key);
        }

        vector<int> ans;

        //前k大從後面取

        for(int i = n; i >= 0; i--) {
            for(int num : bucket[i]) {
                ans.push_back(num);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
