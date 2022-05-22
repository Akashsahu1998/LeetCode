
// Question) 105. Construct Binary Tree from Preorder and Inorder Traversal


// Implementation


// https://www.youtube.com/watch?v=aZNaLrVebKQ
// 1st Approach
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), Where H is the height of the binary tree
class Solution {
private:
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
        
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode * root = new TreeNode(preorder[preStart]);
        int mid = mp[root -> val];
        int prePosition = mid - inStart;
        
        root -> left = solve(preorder, preStart + 1, preStart + prePosition, inorder, inStart, mid - 1, mp);
        
        root -> right = solve(preorder, preStart + prePosition + 1, preEnd, inorder, mid + 1, inEnd, mp);

       return root;
    }    
    

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        
        for(int i = 0; i < inorder.size(); i++) {
           mp[inorder[i]] = i;
        }
        
        return solve(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }
};  


// https://www.youtube.com/watch?v=IH9jN6VdMOc
// 2nd Approach
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), Where H is the height of the binary tree
class Solution {
private:
    TreeNode* solve(vector<int>& preorder, int left, int right, int &index, unordered_map<int, int> &mp){
        
        if (left > right) return NULL;

        TreeNode * root = new TreeNode(preorder[index++]);
        int mid = mp[root -> val];
        
        root -> left = solve(preorder, left, mid-1, index, mp);
        
        root -> right = solve(preorder, mid+1, right, index, mp);

       return root;
    }    
    

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++) {
           mp[inorder[i]] = i;
        }
        
        int index = 0;

        return solve(preorder, 0, preorder.size()-1, index, mp);
    }
};  


// GFG
// 3rd Approach
// Without using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), Where H is the height of the binary tree
class Solution {
private:
    int preIndex = 0;
    TreeNode* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int is, int ie) {
        if(is > ie) return NULL;
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        
        int inIndex;
        for(int itr = is; itr <= ie; itr++){
            if(inorder[itr] == root->val){
                inIndex = itr;
                break;
            }
        }
        root->left = buildBinaryTree(preorder, inorder, is, inIndex-1);
        root->right = buildBinaryTree(preorder, inorder, inIndex+1, ie);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildBinaryTree(preorder, inorder, 0, inorder.size()-1);
    }
};
