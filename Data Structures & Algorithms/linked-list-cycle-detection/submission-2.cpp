/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> st;

        ListNode* cur = head;

        while(cur) {
            if(!st.count(cur)) {
                st.insert(cur);
            }
            else {
                return true;
            }
            cur = cur->next;
        }

        return false;
    }
};
