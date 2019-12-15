class Comp {
public:
    bool operator()(ListNode* p1, ListNode* p2) {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> min_heap;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) {
                continue;
            }
            
            min_heap.push(lists[i]);
        }
        
        ListNode dummy(0);
        ListNode* head = &dummy;
        
        while (!min_heap.empty()) {
            ListNode* top = min_heap.top();
            min_heap.pop();
            if (top->next != NULL) {
                min_heap.push(top->next);
            }
            
            head->next = top;
            head = head->next;
        }
        
        return dummy.next;
    }
};
