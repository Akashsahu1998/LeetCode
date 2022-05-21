
// Question) 987. Vertical Order Traversal of a Binary Tree


// Implementation

// Using Map & Queue
// Level Order Traversal
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // vertical, level, and the list for that level
        map<int, map<int, multiset<int>>> nodes;
        
        // node, vertical and level
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto topValue = q.front();
            q.pop();
            
            TreeNode* node = topValue.first;
            int vertical = topValue.second.first;
            int level = topValue.second.second;
            
            nodes[vertical][level].insert(node->val);
            
            if(node->left){
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right){
                q.push({node->right, {vertical+1, level+1}});
            }
        }
        
        vector<vector<int>> res;
        for(auto a : nodes){
            vector<int> verticalLine;
            
            for(auto sec : a.second){
                verticalLine.insert(verticalLine.end(), sec.second.begin(), sec.second.end());
            }
            
            res.push_back(verticalLine);
        }
        
        return res;
    }
};
