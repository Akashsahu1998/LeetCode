
// Question) 113. Path Sum II


// Implementation

// Time Complexity = O(N^2), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    void findPathSum(TreeNode* root, int targetSum, vector<int> &arr, vector<vector<int>> &resArr){             
        if(!root) return;        
        arr.push_back(root->val);
        targetSum -= root->val;
        if(!root->left && !root->right){
            if(targetSum == 0) resArr.push_back(arr);
        }
        else{
            findPathSum(root->left, targetSum, arr, resArr);
            findPathSum(root->right, targetSum, arr, resArr);
        }
        arr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> resArr;
        vector<int> arr;        
        findPathSum(root, targetSum, arr, resArr);
        return resArr;
    }
};
