
// Question) 104. Maximum Depth of Binary Tree


// Implementation

// 1st Approach
// Using DFS
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
private:
    void dfs(TreeNode* root, int &maxDepth, int curDepth){
        if(!root) return;
        
        maxDepth = max(maxDepth, curDepth);
        dfs(root->left, maxDepth, curDepth+1);
        dfs(root->right, maxDepth, curDepth+1);
        return;
    }
    
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        dfs(root, maxDepth, 1);
        return maxDepth;
    }
};


// 2nd Approach
// Using DFS, without any extra variables
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {    
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


// 3rd Approach
// Using BFS, Using Queue
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {    
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxDepth = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            maxDepth++;
        }
        
        return maxDepth;
    }
};
