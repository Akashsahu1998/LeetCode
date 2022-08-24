
// Question) 230. Kth Smallest Element in a BST


// Implementation

// Using DFS/Recursion
// Time Complexity: O(min(K, N))
// Space Complexity: O(min(K, N))
    
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return 0;
        
        int left = kthSmallest(root->left, k);
        
        // from here only result will always get return by stack call once we will find kth smallest element will reach.
        // for 0 it should not return, bcz we didn't got the kth smallest element yet
        if(left) return left;
        
        k--;
        if(k == 0) return root->val;
        
        return kthSmallest(root->right, k);
    }
};
