class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curt = head;
        
        while (curt) {
            if (curt->val == val) {
                prev->next = curt->next;
                curt = curt->next;
            } else {
                curt = curt->next;
                prev = prev->next;
            }
        }
        
        return dummy.next;
    }
};
