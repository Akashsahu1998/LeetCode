
// Question) 572. Subtree of Another Tree


// Implementation

// Using DFS
// Time Complexity = O(N * M)
// Space Complexity = O(N + M)

class Solution {
private:
    bool isMatchingTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL){
            return root == NULL && subRoot == NULL;
        }
        else if(root->val == subRoot->val){
            return isMatchingTree(root->left, subRoot->left) && isMatchingTree(root->right, subRoot->right);
        }
        else return false;
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if(isMatchingTree(root, subRoot)){
            return true;
        }
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
