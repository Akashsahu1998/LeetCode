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


// Using Unordered Map Approach 
// Time Complexity = O(N), Space Complexity = O(N) where N is the size of the inorder vector

TreeNode* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int is, int ie, unordered_map<int, int> ump, int& preIndex) {
    if(is > ie) return NULL;
    TreeNode *root = new TreeNode(preorder[preIndex++]);
    
    // get the index of the val;
    int inIndex = ump[root->val];
    
    root->left = buildBinaryTree(preorder, inorder, is, inIndex-1, ump, preIndex);
    root->right = buildBinaryTree(preorder, inorder, inIndex+1, ie, ump, preIndex);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
	unordered_map<int, int> ump;    
    for(int itr = 0; itr < inorder.size(); itr++){
        ump[inorder[itr]] = itr;
    }
    return buildBinaryTree(preorder, inorder, 0, inorder.size()-1, ump, preIndex);
}

