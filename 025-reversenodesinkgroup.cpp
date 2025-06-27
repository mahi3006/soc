class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        while (true) {
            ListNode* groupStart = curr;
            ListNode* check = curr;
            for (int i = 0; i < k; i++) {
                if (!check) return dummy->next;
                check = check->next;
            }

            ListNode* prev = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
