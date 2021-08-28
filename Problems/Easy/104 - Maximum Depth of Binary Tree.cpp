
// Question) 104. Maximum Depth of Binary Tree


// Implementation

// Recursive Approach 
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}


// BFS Approach
// Time Complexity = O(N), Space Complexity = O(W) where W is the width of the Binary Tree
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int count = 0;        
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        count++;
        int size = q.size();
        for (int i = 0; i < size; i++){
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);                    
            if (cur->right) q.push(cur->right);
        }
    }        
    return count;
}
