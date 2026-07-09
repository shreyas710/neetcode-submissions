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
    int cnt_nodes(ListNode* head) {
        int cnt = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int cnt = cnt_nodes(head);
        if (cnt < k) return head;

        ListNode* prev = nullptr, *curr = head, *nex;

        cnt = 0;
        while (cnt < k && curr != nullptr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            cnt++;
        }

        if (nex) {
            head->next = reverseKGroup(nex, k);
        }

        return prev;
    }
};
