
// Question) 111. Minimum Depth of Binary Tree


// Implementation

// DFS Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:    
    int minDepth(TreeNode* root) {
        return (root == NULL) ? 0
        : ((!root->left) && (!root->right)) ? 1
        : (!root->left) ? minDepth(root->right) + 1
        : (!root->right) ? minDepth(root->left) + 1
        : min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};


// BFS Approach
// Time Complexity = O(N), Space Complexity = O(W) where W is the width of the Binary Tree

class Solution {
public:    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int countMinDepth = 0;
        while(!q.empty()){
            int size = q.size();
            countMinDepth++;
            for(int itr = 0; itr < size; itr++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                if(!cur->left && !cur->right) return countMinDepth;
            }
        }
        return countMinDepth;
    }
};
