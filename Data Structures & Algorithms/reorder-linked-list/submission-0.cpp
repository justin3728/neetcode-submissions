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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // 找第一段的前一格
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        ListNode* cur = slow->next;
        slow->next = nullptr; 
        
        //第二段反轉
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* nxt= cur->next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
        }

        //雙Head交叉 head, prev
        ListNode* head2 = prev;
        ListNode* head1 = head;
        
        
        while(head2) {
            ListNode* nxt1 = head1->next;
            ListNode* nxt2 = head2->next;
            head1->next = head2;
            head2->next = nxt1;
            head1 = nxt1;
            head2 = nxt2;
        }
        
    }
};
