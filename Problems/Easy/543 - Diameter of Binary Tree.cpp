
// Question) 543. Diameter of Binary Tree


// Implementation

// DFS Approach in C++
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    int findDiameter(TreeNode* root, int &res){
        if(root == NULL) return 0;
        int lh = findDiameter(root->left, res);
        int rh = findDiameter(root->right, res);
        res = max(res, lh+rh+1);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        findDiameter(root, res);
        return res-1;
    }
};