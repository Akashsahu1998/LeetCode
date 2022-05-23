
// Question) 98. Validate Binary Search Tree


// Implementation

// 1st Approach
// Iterative Approach
// Using Stack & Previous Pointer
// Time Complexity = O(N), where N is the total nuumber of nodes in the Binary Tree
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



// 2nd Approach
// Recursive / DFS Approach
// Time Complexity = O(N), where N is the total nuumber of nodes in the Binary Tree
// Space Complexity = O(N), In the case of skewed tree it will read all the n nodes in the Binary Tree
// But, this approach is fine, but we can't rely over the max & min value, bcz the constraint can increase any time in future.
class Solution {
private:
    bool solve(TreeNode* root, long long minValue, long long maxValue){
        if(!root) return true;
        
        if(root->val <= minValue || root->val >= maxValue) return false;
        
        return solve(root->left, minValue, root->val) && solve(root->right, root->val, maxValue);
    }

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
