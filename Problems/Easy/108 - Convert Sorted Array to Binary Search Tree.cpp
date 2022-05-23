
// Question) 108. Convert Sorted Array to Binary Search Tree


// Implementation

// Using Divide & Conquer strategy
// Time Complexity : O(N)
// Space Complexity : O(H), where H is the height of the BST

class Solution {
private:
    TreeNode* solve(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        
        int mid = start + (end - start)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = solve(nums, start, mid-1);
        root->right = solve(nums, mid+1, end);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
