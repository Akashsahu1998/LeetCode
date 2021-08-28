
// Question) 101. Symmetric Tree


// Implementation

// Recursive Approach 
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

bool checkIsSymmetric(TreeNode* r1, TreeNode* r2) {
    // if both are null
    if(!r1 && !r2) return true;
    
    // if anyone is null and another one is not null
    if(!r1 || !r2) return false;
    
    // checking if value are equal or not
    return (r1->val == r2->val) && checkIsSymmetric(r1->left, r2->right) && checkIsSymmetric(r1->right, r2->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return (checkIsSymmetric(root->left, root->right));        
}
