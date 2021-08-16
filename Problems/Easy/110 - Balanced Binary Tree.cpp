
// Question) 110. Balanced Binary Tree


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

int checkBalancedBinaryTree(TreeNode* root){
    if(root == NULL) return 0;
    int left = checkBalancedBinaryTree(root->left);
    int right = checkBalancedBinaryTree(root->right);
    if(left != -1 && right != -1){
        if(abs(left-right) > 1) return -1;
        else{
            return max(left, right) + 1;
        }
    }
    return -1;
}

bool isBalanced(TreeNode* root) {
    if(checkBalancedBinaryTree(root) == -1) return false;
    else return true;
}
