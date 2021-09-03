// Question) 105. Construct Binary Tree from Preorder and Inorder Traversal


// Implementation

// Naive Approach 
// Time Complexity = O(N^2), Space Complexity = O(H) where H is the height of the Binary Tree

TreeNode* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int is, int ie, int& preIndex) {
    if(is > ie) return NULL;
    TreeNode *root = new TreeNode(preorder[preIndex++]);
    
    int inIndex;
    for(int itr = is; itr <= ie; itr++){
        if(inorder[itr] == root->val){
            inIndex = itr;
            break;
        }
    }
    root->left = buildBinaryTree(preorder, inorder, is, inIndex-1, preIndex);
    root->right = buildBinaryTree(preorder, inorder, inIndex+1, ie, preIndex);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildBinaryTree(preorder, inorder, 0, inorder.size()-1, preIndex);
}

