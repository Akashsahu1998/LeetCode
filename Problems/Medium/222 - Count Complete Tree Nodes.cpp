
// Question) 222. Count Complete Tree Nodes


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// Efficient Approach
// Time Complexity = O(Log(n)^2), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftHeight = 0, rightHeight = 0;
        TreeNode *cur = root;
        while(cur != NULL){
            leftHeight++;
            cur = cur->left;
        }
        cur = root;
        while(cur != NULL){
            rightHeight++;
            cur = cur->right;
        }
        if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
