class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums) {
            if(!s.count(num)) {
                s.insert(num);
            }
            else {
                return true;
            }
        }

        return false;
    }
};