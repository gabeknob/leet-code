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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cursor = head;
        ListNode* rev = new ListNode();

        while (cursor) {
            st.push(cursor);
            cursor = cursor->next;
        }

        cursor = rev;

        while (st.size()) {
            cursor->next = st.top();
            cursor = cursor->next;
            st.pop();
        }

        cursor->next = nullptr;
        
        return rev->next;
    }
};
