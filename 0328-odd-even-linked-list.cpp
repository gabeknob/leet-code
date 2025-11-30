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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* evenstart;
        ListNode* divider;
        ListNode* cursor = head;
        int aux = 1;

        while (cursor) {
            if (aux % 2 == 1)
                divider = cursor;

            cursor = cursor->next;
            aux++;
        }

        ListNode* prev = nullptr;
        evenstart = divider;
        cursor = head;
        aux = 1;

        while (cursor != divider) {
            if (aux % 2 == 0) {
                prev->next = cursor->next;
                cursor->next = evenstart->next;
                evenstart->next = cursor;
                evenstart = evenstart->next;

                cursor = prev;
            }

            prev = cursor;
            cursor = prev->next;
            aux++;
        }

        return head;
    }
};
