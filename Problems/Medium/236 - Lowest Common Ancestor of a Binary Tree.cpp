
// Question) 236. Lowest Common Ancestor of a Binary Tree


// Implementation

// 1st Approach Using path
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
// In this solution we require three traversal of binary tree (0(N)+0(N)+0(N)) => 3(0(N)) => 0(N).

class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* node){
        if(root == NULL) return false;
        path.push_back(root);
        if(root == node) return true;
        if(findPath(root->left, path, node) || findPath(root->right, path, node)) return true;
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if(findPath(root, path1, p) == false || findPath(root, path2, q) == false) return NULL;
        int itr = 0;
        for(itr; itr < min(path1.size(), path2.size()); itr++){
            if(path1[itr] != path2[itr]) break;
        }
        return path1[itr-1];
    }
};
