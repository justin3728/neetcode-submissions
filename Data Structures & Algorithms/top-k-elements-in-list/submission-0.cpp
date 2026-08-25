class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }
        
        vector<pair<int, int>> freq;
        
        //轉array之後sort
        for(auto& [key, value] : mp) {
            freq.push_back({key, value});
        }

        sort(freq.begin(), freq.end(), 
            [](auto& a, auto& b) {
                return a.second > b.second;    
            }
        );

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
