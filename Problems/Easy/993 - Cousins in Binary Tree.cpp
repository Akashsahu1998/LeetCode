
// Question) 993. Cousins in Binary Tree


// Implementation

// Using DFS
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
private:
    int findParentAndHeight(TreeNode* root, int &parent, int value, int height){
        
        // if value didn't found then return 0
        if(!root)
            return 0;
        
        // if value found, then simply return height
        if(value == root->val){
            return height;
        }
        
        // work for left side
        // update the parent
        parent = root->val;
        int left = findParentAndHeight(root->left, parent, value, height+1);
        // if left is 0 it means value didn't found on left side
        if(left)
            return left;
        
        // work for right side
        // update the parent
        parent = root->val;
        int right = findParentAndHeight(root->right, parent, value, height+1);
        // if right is 0 it means value didn't found on right side
        if(right)
            return right;
        
        // in last if we didn't found value on both left & right side, return 0
        return 0;
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        // if root is x or y, then simply return false, bcz there is no parent
        if(root->val == x || root->val == y) 
            return false;
        
        // will pass parent as reference, bcz we will be storing it for future purpose
        int xParent = -1;
        int xHeight = findParentAndHeight(root, xParent, x, 0);
        
        int yParent = -1;
        int yHeight = findParentAndHeight(root, yParent, y, 0);
        
        // if parent are not same and heights are same for both value, then return true, otherwise false
        if(xParent != yParent && xHeight == yHeight)
            return true;
        
        return false;
    }
};
