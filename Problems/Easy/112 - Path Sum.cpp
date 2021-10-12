
// Question) 112. Path Sum


// Implementation

// 1st Approach using the helper(findPath) method
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


// 2nd Approach without using the any helper method
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {        
        if(root == NULL) return false;
        targetSum -= root->val;
        
        if(root->left == NULL && root->right == NULL){
            return (targetSum == 0) ? true : false;
        }
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));        
    }
};
