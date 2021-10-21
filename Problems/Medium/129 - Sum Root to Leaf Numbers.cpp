
// Question) 129. Sum Root to Leaf Numbers


// Implementation

// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
class Solution {
public:
    void sumOfNum(TreeNode* root, int num, int &ans){
        if(!root) return;
        num = num * 10 + root->val;
        if(!root->left && !root->right) ans += num;
        else{
            sumOfNum(root->left, num, ans);
            sumOfNum(root->right, num, ans);
        }        
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sumOfNum(root, 0, ans);
        return ans;
    }
};
