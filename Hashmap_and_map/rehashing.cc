class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = hashTable.size();
        capacity *= 2;
        vector<ListNode*> result(capacity);
        vector<ListNode*> p_new(capacity);
        
        for (ListNode* p: hashTable) {
            while (p) {
                int index = p->val % capacity;
                if (index < 0) {
                    index += capacity;
                }
                if (result[index] == NULL) {
                    result[index] = new ListNode(p->val);
                    p_new[index] = result[index];
                } else {
                    p_new[index]->next = new ListNode(p->val);
                    p_new[index] = p_new[index]->next; 
                }
                p = p->next;
            }
        }
        
        return result;
    }
};
