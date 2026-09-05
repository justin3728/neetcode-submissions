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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy->next;
        int num = 0;

        //數量
        while(cur) {
            cur = cur->next;
            num++;
        }

        ListNode* prev = nullptr;
        ListNode* p0 = dummy;
        cur = p0->next;

        while(num >= k) {
            num -= k;
            for(int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }


            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = prev;
            p0 = nxt;

        }

        return dummy->next;
        
    }
};
