
// Question) 114. Flatten Binary Tree to Linked List


// Implementation

// Naive Approach
// Using Stack
// 2 traversal
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    // creating stack using preorder traversal
    void createStack(TreeNode* root, stack<TreeNode*> &st){
        if(!root) return;        
        st.push(root);
        createStack(root->left, st);
        createStack(root->right, st);        
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        createStack(root, st);
        
        // Putting top of the stack into temp and in temp->left putting NULL, and in tempRight putting
        // root, and then pointing root = temp; and poping the top
        root = NULL;
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            temp->left = NULL;
            temp->right = root;            
            root = temp;            
        }        
    }    
};



// 2nd Approach
// 1 Traversal
// Recursive Approach
// Efficient Approach
// Post Order Traversal
// Time Complexity = O(N), Space Complexity = O(N), considering the recursion call stack
class Solution {
private:
    TreeNode *prevPtr = NULL;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->right = NULL;
        prevPtr = root;
    }
};



// 3rd Approach
// Most Efficient Approach
// Iterative Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                TreeNode *run = cur->left;                
                while(run->right){
                    run = run->right;
                }
                // move all the nodes from cur->right to run->right
                run->right = cur->right;
                
                // move all the nodes from cur->left to cur->right, bcz we dont need left side
                cur->right = cur->left;
                
                // just make the left side null
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
