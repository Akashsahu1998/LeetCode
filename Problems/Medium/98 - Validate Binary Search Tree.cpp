
// Question) 98. Validate Binary Search Tree


// Implementation

// Using Stack & Previous Pointer
// Time Complexity = O(N)
// Space Complexity = O(H), where H is the Height of the Binary Tree
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* previous = NULL;
        
        while(root != NULL || !st.empty()){
            
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            if(previous != NULL && previous->val >= root->val) return false;
            
            previous = root;
            root = root->right;
        }
        
        return true;
    }
};
