class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for(int right = 0; right < nums.size(); right++) {
            pq.push({nums[right], right});

            if(right < k - 1) continue;

            int left = right - k + 1;
            
            while(pq.top().second < left) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
