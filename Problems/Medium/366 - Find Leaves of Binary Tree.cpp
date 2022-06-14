
// Question) 366. Find Leaves of Binary Tree


// Implementation

// DFS Approach
// Time Complexity : O(N), where N is the total number of nodes in the binary tree
//Space Complexity : O(H), where H is the height of the binary tree, not considering the 2-D vector bcz that's a part of result
class Solution {
private:
    int findLeavesUsingHeight(TreeNode* root, vector<vector<int>> &res){
        
        // assuming heights starts from 0, thats why return -1
        if(!root){
            return -1;
        }
        
        int left = findLeavesUsingHeight(root->left, res);
        int right = findLeavesUsingHeight(root->right, res);
        
        int curHeight = max(left, right) + 1;
        
        if(curHeight == res.size()){
            // pushing empty vector, so later we can put values into it using index
            res.push_back({});
        }
        
        res[curHeight].push_back(root->val);
        
        return curHeight;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        findLeavesUsingHeight(root, res);
        return res;
    }
};
