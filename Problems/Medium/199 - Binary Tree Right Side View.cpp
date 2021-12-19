
// Question) 199. Binary Tree Right Side View


// Implementation

// BFS
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            bool flag = true;
            res.push_back(q.front()->val);
            
            for(int itr = 0; itr < q.size(); itr++){
                TreeNode* temp = q.front();
                q.pop();                
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};


// DFS
// Time Complexity = O(N), Space Complexity = O(H)
class Solution {
public:
    void findRightSideView(TreeNode* root, vector<int> &res, int level){
        if(!root) return;
        if(level > res.size()) res.push_back(root->val);
        findRightSideView(root->right, res, level+1);
        findRightSideView(root->left, res, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        findRightSideView(root, res, 1);
        return res;
    }
};
