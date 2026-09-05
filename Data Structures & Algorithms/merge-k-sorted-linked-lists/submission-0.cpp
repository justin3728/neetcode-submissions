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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        //不能傳nullptr
        for(ListNode* node : lists) {
            if(node) pq.push(node);
        }

        while(!pq.empty()) {
            ListNode* node = pq.top();
            cur->next = node;
            cur = cur->next;
            pq.pop();
            if(node->next) pq.push(node->next);
        }

        return dummy->next;
    }
};
