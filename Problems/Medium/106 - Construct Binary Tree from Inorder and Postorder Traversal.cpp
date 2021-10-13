
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

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(N) Where N is the number of element into Inorder array
// Giving TLE
class Solution {
public:    
    TreeNode* builtTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &index, unordered_map<int, int> mp){
        if(inStart > inEnd) return NULL;
        
        int curr = postorder[index];
        TreeNode* root = new TreeNode(curr);
        index--;
        
        if(inStart == inEnd) return root;
        int inIndex = mp[curr];
        
        root->right = builtTree(inorder, postorder, inIndex+1, inEnd, index, mp);
        root->left = builtTree(inorder, postorder, inStart, inIndex-1, index, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int itr = 0; itr < inorder.size(); itr++)
                mp[inorder[itr]] = itr;
        int index = inorder.size() - 1;
        return builtTree(inorder, postorder, 0, postorder.size()-1, index, mp);
    }
};
