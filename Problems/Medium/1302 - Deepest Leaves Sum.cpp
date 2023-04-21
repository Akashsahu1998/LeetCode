
// Question) 1302. Deepest Leaves Sum


// Implementation

// Using DFS
// Time Complexity = O(N)
// Space Complexity = O(H)

class Solution {
private:
    int solve(TreeNode* root, int level, int &maxLevel, int &sum){
        if(!root) return 0;
        
        if(level > maxLevel){
            sum = 0;
            sum += root->val;
            maxLevel = level;
        }
        else if(level == maxLevel){
            sum += root->val;
        }
        
        solve(root->left, level+1, maxLevel, sum);
        solve(root->right, level+1, maxLevel, sum);
        
        return sum;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxLevel = 0, level = 0, sum = 0;
        solve(root, level, maxLevel, sum);
        return sum;
    }
};


// Idea:
// 1) Try to get the result based on level and max level and also make sum 0 when new max level we get
// 2) If max level and level are equal then add both values into result
