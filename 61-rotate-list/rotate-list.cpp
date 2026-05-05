class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        int len = 1;

        while (temp->next) {
            temp = temp->next;
            len++;
        }

        temp->next = head;
        k = k % len;

        int steps = len - k;
        while (steps--) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};