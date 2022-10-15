
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


// Same as 2nd Approach but nicely refactored
// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the Binary Tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if root is null, return false
        if(!root) return false;
        
        // if we found target sum && also the node is leaf node, so return true
        if(root->val == targetSum && !root->left && !root->right) return true;
        
        // if we find targetsum any side on left or right, return true
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
