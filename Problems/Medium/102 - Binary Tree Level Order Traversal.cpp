
// Question) 102. Binary Tree Level Order Traversal


// Implementation

// Using BFS (Queue)
// Time Complexity = O(N)
// Space Complexity = O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> arr;
            
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                
                arr.push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            res.push_back(arr);
        }
        
        return res;
    }
};
