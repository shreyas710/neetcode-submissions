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
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;

        while (1) {
            int minn = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) continue;
                if (minn == -1 || lists[i]->val < lists[minn]->val)
                    minn = i;
            }

            if (minn == -1) break;
            cur->next = lists[minn];
            lists[minn] = lists[minn]->next;
            cur = cur->next;
        }

        return ans->next;
    }
};
