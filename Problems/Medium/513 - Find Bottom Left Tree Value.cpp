
// Question) 513. Find Bottom Left Tree Value


// Implementation

// 1st Approach
// Using level order traversal from left to right
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        
        while(!q.empty()){
            int size = q.size();
            for(int itr = 0; itr < size; itr++){
                TreeNode *temp = q.front();            
                q.pop();
                if(itr == 0) ans = temp->val;                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};


// 2nd Approach
// Using level order traversal from right to left
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        
        while(!q.empty()){
            int size = q.size();
            for(int itr = 0; itr < size; itr++){
                TreeNode *temp = q.front();            
                q.pop();
                if(itr == size-1) ans = temp->val;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return ans;
    }
};


// 3rd Approach
// Efficient Solution
// Using DFS
// Time Complexity = O(N), Space Complexity = O(H), where H is the height of the tree
class Solution {
public:
    void findBottomLeftValue(TreeNode* root, int depth, int &maxDepth, int &ans) {
        if(!root) return;
        findBottomLeftValue(root->left, depth+1, maxDepth, ans);
        findBottomLeftValue(root->right, depth+1, maxDepth, ans);
        
        if(depth > maxDepth){
            maxDepth = depth;
            ans = root->val;
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {        
        int ans = root->val;
        int depth = 0, maxDepth = 0;
        findBottomLeftValue(root, depth, maxDepth, ans);
        return ans;
    }
};
