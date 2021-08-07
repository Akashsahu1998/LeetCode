
// Question) 94. Binary Tree Inorder Traversal


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

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
