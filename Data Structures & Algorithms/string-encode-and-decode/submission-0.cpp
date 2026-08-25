class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string str : strs) {
            int num = str.size();
            
            s += to_string(num) + '#' + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        int idx = 0;
        int num = s.size();
        string length;
        vector<string> ans;

        while(idx < num) {
            if(s[idx] != '#') {
                length += s[idx];
                idx++;
                continue;
            }
            else{
                int l = stoi(length);
                length.clear();
                int startIdx = ++idx;
                ans.push_back(s.substr(startIdx, l));
                idx = startIdx + l;
            }
        }

        return ans;
    }
};
