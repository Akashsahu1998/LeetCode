
// Question) 199. Binary Tree Right Side View


// Implementation

// DFS
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
