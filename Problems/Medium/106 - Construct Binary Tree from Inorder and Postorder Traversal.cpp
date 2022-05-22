
// Question) 106. Construct Binary Tree from Inorder and Postorder Traversal


// Implementation

// 1st Approach
// Naive Approach
// Time Complexity = O(N^2)
// Space Complexity = O(H), Where H is the height of the binary tree
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

// https://www.youtube.com/watch?v=IH9jN6VdMOc
// 2nd Approach
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), Where H is the height of the binary tree
class Solution {
    private:
    TreeNode* solve(vector<int>& postorder, int left, int right, int &index, unordered_map<int, int> &mp){
        
        if (left > right) return NULL;

        TreeNode * root = new TreeNode(postorder[index--]);
        int mid = mp[root -> val];
        
        root->right = solve(postorder, mid+1, right, index, mp);

        root->left = solve(postorder, left, mid-1, index, mp);
        
        return root;
    }   
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++) {
           mp[inorder[i]] = i;
        }
        
        int index = postorder.size()-1;

        return solve(postorder, 0, postorder.size()-1, index, mp);
    }
};


// GFG
// 3rd Approach
// Without using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), Where H is the height of the binary tree
class Solution {
public:    
    TreeNode* buildBinaryTree(vector<int>& inorder, vector<int>& postorder, int &inorderPosition, int &postorderPosition, int stop){
        if(postorderPosition == -1) return NULL;
        
        if(inorder[inorderPosition] == stop){
            inorderPosition--;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postorderPosition--]);
        
        root->right = buildBinaryTree(inorder, postorder, inorderPosition, postorderPosition, root->val);
        root->left = buildBinaryTree(inorder, postorder, inorderPosition, postorderPosition, stop);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderPosition = inorder.size()-1;
        int postorderPosition = postorder.size()-1;
        return buildBinaryTree(inorder, postorder, inorderPosition, postorderPosition, INT_MIN);
    }
};
