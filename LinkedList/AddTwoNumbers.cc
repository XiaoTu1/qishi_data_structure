class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *p1 = l1, *p2 = l2, *curt = &dummy;
        
        int carry = 0;
        while (p1 && p2) {
            int value = p1->val + p2->val + carry;
            curt->next = new ListNode(value % 10);
            carry = value / 10;
            p1 = p1->next;
            p2 = p2->next;
            curt = curt->next;
        }
        
        while (p1) {
            int value = p1->val + carry;
            curt->next = new ListNode(value % 10);
            carry = value / 10;
            p1 = p1->next;
            curt = curt->next;
        }
        
        while (p2) {
            int value = p2->val + carry;
            curt->next = new ListNode(value % 10);
            carry = value / 10;
            p2 = p2->next;
            curt = curt->next;
        }
        
        if (carry) {
            curt->next = new ListNode(1);        
        }
        
        return dummy.next;
     }
};
