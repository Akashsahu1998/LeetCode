
// Question) 543. Diameter of Binary Tree


// Implementation

// 1st Approach
// Using DFS
// Time Complexity : (N)
// Space Complexity : (H), where H is the height of the binary tree, if all elements are on left/right side, then H will become equal to N

class Solution {
    int dfs(TreeNode* root, int &maxAns){
        if(!root) return 0;
        int leftHeight = dfs(root->left, maxAns);
        int rightHeight = dfs(root->right, maxAns);
        maxAns = max(maxAns, leftHeight+rightHeight);
        
        // taking max, bcz we wan't max left/right height, not the total number of nodes.
        return 1 + max(leftHeight, rightHeight);
    }
        
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxAns = 0;
        dfs(root, maxAns);
        return maxAns;
    }
};


// 2nd Approach
// Using DFS
// Time Complexity : (N)
// Space Complexity : (H), where H is the height of the binary tree, if all elements are on left/right side, then H will become equal to N

 class Solution {
     int dfs(TreeNode* root, int &maxAns){
         if(!root) return 0;
         int leftHeight = dfs(root->left, maxAns);
         int rightHeight = dfs(root->right, maxAns);
         maxAns = max(maxAns, 1+leftHeight+rightHeight);
        
         // taking max, bcz we wan't max left/right height, not the total number of nodes.
         return 1 + max(leftHeight, rightHeight);
     }
        
 public:
     int diameterOfBinaryTree(TreeNode* root) {
         int maxAns = 0;
         dfs(root, maxAns);
         return maxAns-1;
     }
 };
