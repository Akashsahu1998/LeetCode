
// Question) 112. Path Sum


// Implementation

// 1st Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    bool findPath(TreeNode* root, int targetSum, int sum){
        if(root == NULL) return false;
        sum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            return (sum == targetSum) ? true : false;
        }
        return (findPath(root->left, targetSum, sum) || findPath(root->right, targetSum, sum));        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {        
        return findPath(root, targetSum, 0);
    }
};
