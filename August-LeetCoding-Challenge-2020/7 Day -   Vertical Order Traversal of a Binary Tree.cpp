/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return {};
        
        map<pair<int, int>, set<int>> map;
        int maxValue = INT_MIN; int minValue = INT_MAX;
        
        dfs(map, root, 0, 0, maxValue, minValue);
        
        vector<vector<int>> verticalOrderResult(maxValue - minValue + 1);
        
        for (const auto& pair : map) {
            int index = pair.first.first - minValue;
            verticalOrderResult[index].insert(verticalOrderResult[index].end(), pair.second.begin(), pair.second.end());
        }
        return verticalOrderResult;
    }
    
    void dfs(map<pair<int, int>, set<int>>& map, TreeNode* root, int a, int b, int& maxValue, int& minValue) {
        if (root == NULL) return;
            
        map[{a, b}].insert(root->val);
        maxValue = max(maxValue, a);
        minValue = min(minValue, a);
        
        dfs(map, root->left, a - 1, b + 1, maxValue, minValue);
        dfs(map, root->right, a + 1, b + 1, maxValue, minValue);
    }
};
