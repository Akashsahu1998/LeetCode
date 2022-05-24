
// Question) 653. Two Sum IV - Input is a BST


// Implementation

// Using BST next & before iterator strategy and two pointer's approach
// Time Complexity : O(N)
// Space Complexity : O(H) + O(H) => O(H), 1st O(H) for next & 2nd O(H) for before

class BSTIterator{
private:
    void pushAll(TreeNode* root){
        for(TreeNode* i = root; i != NULL; ){
            st.push(i);
            
            if(reverse){
                i = i->right;
            }
            else{
                i = i->left;
            }
        }
    }

public:
    stack<TreeNode*> st;
    
    // reverse -> true = before
    // reverse -> false = next;
    bool reverse;
    
    BSTIterator(TreeNode* root, bool reverseValue){
        reverse = reverseValue;
        pushAll(root);
    }
    
    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(reverse) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j){
            if(i+j == k) return true;
            else if(i+j > k) j = r.next();
            else i = l.next();
        }
        
        return false;
    }
};
