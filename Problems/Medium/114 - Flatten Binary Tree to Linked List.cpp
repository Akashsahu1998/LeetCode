
// Question) 114. Flatten Binary Tree to Linked List


// Implementation

// Naive Approach
// Using Stack
// 2 traversal
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    // creating stack using preorder traversal
    void createStack(TreeNode* root, stack<TreeNode*> &st){
        if(!root) return;        
        st.push(root);
        createStack(root->left, st);
        createStack(root->right, st);        
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        createStack(root, st);
        
        // Putting top of the stack into temp and in temp->left putting NULL, and in tempRight putting
        // root, and then pointing root = temp; and poping the top
        root = NULL;
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            temp->left = NULL;
            temp->right = root;            
            root = temp;            
        }        
    }    
};
