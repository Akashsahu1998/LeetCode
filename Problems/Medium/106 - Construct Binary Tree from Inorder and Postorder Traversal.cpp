
// Question) 106. Construct Binary Tree from Inorder and Postorder Traversal


// Implementation

// Naive Approach
// Time Complexity = O(N^2), Space Complexity = O(H) Where H is the height of the binary tree
class Solution {
public:
    int search(vector<int>& inorder, int inStart, int inEnd, int key){        
        int itr = inStart;
        for(; itr <= inEnd; itr++){
            if(key == inorder[itr]) break;
        }
        return itr;
    }
    
    TreeNode* builtTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        if(inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
                
        if(inStart == inEnd) return root;
        int index = search(inorder, inStart, inEnd, root->val);
        
        root->left = builtTree(inorder, postorder, inStart, index-1, postStart, postStart-inStart+index-1);
        root->right = builtTree(inorder, postorder, index+1, inEnd, postEnd-inEnd+index, postEnd-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return builtTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
