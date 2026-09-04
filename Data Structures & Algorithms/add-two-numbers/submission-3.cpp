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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;

        while(l1 || l2 || carry) {
            int n1 = (l1 == nullptr) ? 0 : l1->val;
            int n2 = (l2 == nullptr) ? 0 : l2->val;
            int sum = n1 + n2 + carry;

            cur->next = new ListNode(sum % 10);

            carry = sum / 10;

            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        } 
        return dummy->next;
    }
};
