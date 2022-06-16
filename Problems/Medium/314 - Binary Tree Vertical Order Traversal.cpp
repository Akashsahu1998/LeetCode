
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
        
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> bfsQueue;
        bfsQueue.push({0, root});
        
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            for(int i = 0; i < size; i++){
                auto node = bfsQueue.front().second;
                int index = bfsQueue.front().first;
                bfsQueue.pop();
                
                mp[index].push_back(node->val);
                
                if(node->left){
                    bfsQueue.push({index-1, node->left});
                }
                if(node->right){
                    bfsQueue.push({index+1, node->right});
                }
            }
        }
        
        for(auto m : mp){
            res.push_back(m.second);
        }
        
        return res;
    }
};
