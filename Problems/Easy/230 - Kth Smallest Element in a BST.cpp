
// Question) 230. Kth Smallest Element in a BST


// Implementation

// Using Recursion
// Time Complexity: O(min(K, N))
// Space Complexity: O(min(K, N))
    
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return 0;
        
        int left = kthSmallest(root->left, k);
        if(left) return left;
        
        k--;
        if(k == 0) return root->val;
        
        return kthSmallest(root->right, k);
    }
};
