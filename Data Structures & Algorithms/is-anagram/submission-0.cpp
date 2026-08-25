class Solution {
public:
    bool isAnagram(string s, string t) {
        //利用一個大小為26 的array存 各字母的數量
        //另一個迴圈 把數量減少 
        //最後檢查是否array為空
        vector<int> array(26);

        for(char c : s) {
            array[c - 'a']++;
        }

        for(char c : t) {
            array[c - 'a']--;
        }

        for(int i = 0; i < array.size(); i++) {
            if(array[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
