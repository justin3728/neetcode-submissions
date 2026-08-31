class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //從mid找 如果mid 可滿足 往左區間找更小k, 不滿足超時 往右找
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while(left <= right) {
            //最大值跟最小值 非index
            int mid = left + (right - left) / 2;
            int rate = mid;
            int time = 0;

            for(int pile : piles) {
                time += (pile + rate - 1) / rate; 
            }

            if(time > h) {
                left = mid + 1;
            }
            else {
                ans = min(ans, rate);
                right = mid - 1;
            }
        }

        return ans;

        
    }
};
