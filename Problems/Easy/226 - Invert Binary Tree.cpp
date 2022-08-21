
// Question) 226. Invert Binary Tree


// Implementation

// Recursive Approach
// Using DFS
// Time Complexity : O(N)
// Space Complexity : O(H), Where H is the height of the Binary Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        
        // swap the left & right child of parent node
        swap(root->left, root->right);
        
        return root;
    }
};


// Iterative Approach
// Using Stack
// Time Complexity : O(N)
// Space Complexity : O(W), Where W is the width of the Binary Tree**

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        stack<TreeNode*> st;        
        st.push(root);
        
        while(st.size() > 0){
            TreeNode* top = st.top();
            st.pop();
            
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
            
            // swap the left & right child of parent node
            swap(top->left, top->right);
        }
        
        return root;
    }
};
