
// Question) 94. Binary Tree Inorder Traversal


// Implementation

// Using Recursion
// 1st Approach
// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the Binary Tree

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);    
        }
        return res;
    }
};



// Using Recursion
// 2nd Approach
// Time Complexity : O(N)
// Space Complexity : O(N), where H is the height of the Binary Tree

class Solution {
private:
    void solve(TreeNode* root, vector<int> &res){
        if(!root) return;
        
        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        solve(root, res);
        
        return res;
    }
};
