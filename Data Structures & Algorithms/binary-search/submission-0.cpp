class Solution {
public:
    int search(vector<int>& nums, int target) {
        //[left, right)
        int left = 0;
        int right = nums.size();

        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return mid; 
            }
            else if(nums[mid] > target) {
                //右開所以right不會被搜尋。
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
