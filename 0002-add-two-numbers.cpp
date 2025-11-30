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
        int sum;
        bool acc = false;

        ListNode* final = new ListNode();
        ListNode* c = final;

        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            sum = val1 + val2;
            c->val = (sum + acc) % 10;
            acc = (sum + acc) >= 10;

            if ((l1 && l1->next) || (l2 && l2->next)) {
                c->next = new ListNode();
            } else if (acc) {
                c->next = new ListNode(1);
            }

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            c = c->next;
        }

        return final;
    }
};
