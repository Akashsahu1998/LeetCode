
// Question) 513. Find Bottom Left Tree Value


// Implementation

// Using level order traversal from left to right
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        
        while(!q.empty()){
            int size = q.size();
            for(int itr = 0; itr < size; itr++){
                TreeNode *temp = q.front();            
                q.pop();
                if(itr == 0) ans = temp->val;                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};


// Using level order traversal from right to left
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        
        while(!q.empty()){
            int size = q.size();
            for(int itr = 0; itr < size; itr++){
                TreeNode *temp = q.front();            
                q.pop();
                if(itr == size-1) ans = temp->val;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return ans;
    }
};
