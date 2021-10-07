
// Question) 108. Convert Sorted Array to Binary Search Tree


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    TreeNode* convertArrayToBST(vector<int>& nums, int start, int end){
        if(start == end) return NULL;
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = convertArrayToBST(nums, start, mid);
        root->right = convertArrayToBST(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertArrayToBST(nums, 0, nums.size());
    }
};
