
// Question) 314. Binary Tree Vertical Order Traversal


// Implementation

// BFS Approach
// Using Queue
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<pair<int, TreeNode*>> bfsQueue;
        unordered_map<int, vector<int>> mp;
        bfsQueue.push({0, root});
        
        // Using these variables to get the min possible column and max possible column, so we don't need to use the map, bcz map can store in sorted order, but with the help of these variables we can run loop from minColumn to maxColumn, and we can get all values in sorted order, so in this way we can also improve our time complexity
        int minColumn = 0, maxColumn = 0;
        
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            for(int i = 0; i < size; i++){
                int column = bfsQueue.front().first;
                TreeNode* node = bfsQueue.front().second;
                bfsQueue.pop();
                
                mp[column].push_back(node->val);
                minColumn = min(minColumn, column);
                maxColumn = max(maxColumn, column);
                
                if(node->left){
                    bfsQueue.push({column-1, node->left});
                }
                if(node->right){
                    bfsQueue.push({column+1, node->right});
                }
            }
        }
        
        for(int i = minColumn; i <= maxColumn; i++){
            res.push_back(mp[i]);
        }
        
        return res;
    }
};


// Algo Steps
// 1) Use unordered map
// 2) use indexing, and consider as a column
