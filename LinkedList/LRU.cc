class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity;    
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        adjust(key);
        
        return hash[key]->next->value;
    }

    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->next->value = value;
            adjust(key);
            return;
        }
        
        if (hash.size() == mCapacity) {
            if (mCapacity == 1) {
                hash.erase(head->next->key);
                delete head->next;
                head->next = NULL;
                tail = head;
            } else {
                ListNode_* p = head->next;
                head->next = p->next;
                hash.erase(p->key);
                hash[p->next->key] = head;
                delete p;
            }   
        }
        
        tail->next = new ListNode_(key, value);
        hash[key] = tail;
        tail = tail->next;
    }
    
    void adjust(int key) {
        if (key == tail->key) {
            return;    
        }
        
        ListNode_* temp = hash[key]->next;
        hash[key]->next = temp->next;
        temp->next = NULL;
        tail->next = temp;
        
        hash[hash[key]->next->key] = hash[key];
        hash[key] = tail;
        tail = tail->next;
        
    }
    
    int mCapacity;
    
    ListNode_ dummy = ListNode_(0, 0);
    ListNode_* head{&dummy};
    ListNode_* tail = head;
    
    unordered_map<int, ListNode_*> hash;
    
};
