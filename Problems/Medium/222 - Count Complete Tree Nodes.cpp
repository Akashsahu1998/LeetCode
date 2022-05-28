
// Question) 222. Count Complete Tree Nodes


// Implementation

// 1st Approach
// Naive Approach
// Using DFS, Preorder Traversal
// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the Binary Tree

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// 2nd Approach
// Efficient Approach
// Using DFS
// Time Compexity : O((logN) ^ 2)
// Space Compexity : O(logN)

class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftHeight = 0, rightHeight = 0;
        TreeNode *cur = root;
        
        // finding left height for a subtree
        while(cur != NULL){
            leftHeight++;
            cur = cur->left;
        }
        cur = root;
        
        // finding right height for a subtree
        while(cur != NULL){
            rightHeight++;
            cur = cur->right;
        }
        
        // if both are equal then directly return the ans
        if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        
        // if not equal then again compute the left height & right height for subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
