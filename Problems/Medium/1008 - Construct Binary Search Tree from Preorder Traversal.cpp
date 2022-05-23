
// Question) 1008. Construct Binary Search Tree from Preorder Traversal


// Implementation

// Using DFS
// Time Complexity: O(N)
// Space Complexity: O(N), bcz of the stack trace

class Solution {
private:
    TreeNode* solve(vector<int> &preorder, int &index, int upperBound){
        if(index == preorder.size() || preorder[index] > upperBound) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        
        root->left = solve(preorder, index, root->val);
        root->right = solve(preorder, index, upperBound);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, upperBound = INT_MAX;
        return solve(preorder, index, upperBound);
    }
};
