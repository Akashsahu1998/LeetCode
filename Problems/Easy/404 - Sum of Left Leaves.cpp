
// Question) 404. Sum of Left Leaves


// Implementation

// 1st Approach Using DFS
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
private:
    void findLeftLeavesSum(TreeNode* root, bool isLeftNode, int& sum){
        
        // if root is null return
        if(!root) return;
        
        // checking if root is leaf node, and also checking its coming from left side or not
        // if condition met true, then add the sum, and do nothing
        if(root->left == NULL && root->right == NULL && isLeftNode){
            sum += root->val;
        }
        
        // go on left side
        findLeftLeavesSum(root->left, true, sum);
        
        // go on right side
        findLeftLeavesSum(root->right, false, sum);
        
        return;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findLeftLeavesSum(root, false, sum);
        return sum;
    }
};


// 2nd Approach Using Stack
// Time Complexity = O(N)
// Space Complexity = O(N)

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
