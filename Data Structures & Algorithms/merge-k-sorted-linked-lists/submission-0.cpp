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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for (auto x: lists) {
            if (x) pq.push(x);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            curr->next = tp;
            curr = curr->next;
            if (tp->next) pq.push(tp->next);
        }

        return dummy->next;
    }
};
