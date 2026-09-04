class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        nums[index] = 下一個節點
        第一輪：
        slow 走 1 步
        fast 走 2 步
        → 找環內相遇點

        第二輪：
        slow 回起點
        兩個都走 1 步
        → 相遇處 = 環入口 = duplicate
        */

        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = nums[0];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
