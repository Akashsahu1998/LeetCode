
// Question) 173. Binary Search Tree Iterator


// Implementation

// Using Stack
// Time Complexity = O(N)
// Space Complexity = O(H)
class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
