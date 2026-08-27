class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        int left = 1;

        //前k個
        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for(int right = k; right < nums.size(); right++) {
            pq.push({nums[right], right});
            
            while(pq.top().second < left) {
                pq.pop();
            }

            ans.push_back(pq.top().first);

            left++;
        }

        return ans;
    }
};
