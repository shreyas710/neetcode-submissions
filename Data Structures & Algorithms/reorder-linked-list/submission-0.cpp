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
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow, *prev = nullptr;
        while (curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode* l1 = head, *l2 = prev;
        while (l2->next != nullptr) {
            ListNode* tmp = l1->next;
            l1->next = l2;
            l1 = tmp;
            tmp = l2->next;
            l2->next = l1;
            l2 = tmp;
        }
    }
};
