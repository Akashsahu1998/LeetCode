
// Question) 103. Binary Tree Zigzag Level Order Traversal


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(W) where W is the width of the Binary Tree

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return res;
        stack<TreeNode*> stackLeftToRight;
        stack<TreeNode*> stackRightToLeft;
        stackLeftToRight.push(root);

        while(!(stackLeftToRight.empty() && stackRightToLeft.empty())){
            vector<int> temp;
            while(!stackLeftToRight.empty()){
                TreeNode* cur = stackLeftToRight.top();
                stackLeftToRight.pop();
                temp.push_back(cur->val);                
                if(cur->left != NULL) 
                    stackRightToLeft.push(cur->left);
                if(cur->right != NULL)
                    stackRightToLeft.push(cur->right);
            }
            
            res.push_back(temp);            
            if(!stackRightToLeft.empty()){
                temp.clear();
                while(!stackRightToLeft.empty()){
                    TreeNode* cur = stackRightToLeft.top();
                    stackRightToLeft.pop();
                    temp.push_back(cur->val);
                    if(cur->right != NULL)
                        stackLeftToRight.push(cur->right);
                    if(cur->left != NULL) 
                        stackLeftToRight.push(cur->left);                
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};
