class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        leftmost = root;
        while (leftmost->left) {
            S.push(leftmost);
            leftmost = leftmost->left;
        }    
    }
    
    /** @return the next smallest number */
    int next() {
        if (p == NULL) {
            p = leftmost;
            return p->val;
        }
        
        if (!p->right) {
            if (S.empty()) {
                return INT_MAX;
            }
            p = S.top();
            S.pop();
            return p->val;
        }
        
        p = p->right;
        while (p->left) {
            S.push(p);
            p = p->left;
        }
        
        return p->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (leftmost == NULL) {
            return false;
        }
            
        if (p == NULL && leftmost) {
            return true;
        }
        
        if (!S.empty() || p->right) {
            return true;
        } else {
            return false;
        }
    }

private:
    stack<TreeNode*> S;
    TreeNode* leftmost = NULL;
    TreeNode* p = NULL;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
