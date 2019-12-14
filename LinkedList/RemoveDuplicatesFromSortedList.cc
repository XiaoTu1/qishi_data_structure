class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }    
        
        ListNode *left = head, *right = left->next;
        while (right) {
            if (right->val != left->val) {
                left->next = right;
                left = left->next;
            }
            right = right->next;
        }
        left->next = NULL;
        
        return head;
    }
};
