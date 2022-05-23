
// Question) 700. Search in a Binary Search Tree


// Implementation

// Time Complexity : O(logN)
// Space Complexity : O(logN)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};
