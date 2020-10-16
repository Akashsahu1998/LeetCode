class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        
        if(!root) return 0;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *current = st.top();
            st.pop();
            if(current -> left){
                if(!current -> left -> left && !current -> left -> right) sum += current -> left -> val;
                else st.push(current->left);
            } 
            if(current -> right) if(current -> right -> left || current -> right -> right) st.push(current -> right);
        }        
        return sum;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
