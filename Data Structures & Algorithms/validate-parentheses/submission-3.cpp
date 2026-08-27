class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if(st.empty()) return false;

                char left = st.top();
                
                if(c == ')' && left != '(') return false;
                if(c == ']' && left != '[') return false;
                if(c == '}' && left != '{') return false;

                st.pop();
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};
