
// Question) 199. Binary Tree Right Side View


// Implementation
// BFS Method

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(W) where W is the Width of the Binary Tree

class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int itr = 0; itr < size; itr++){
                TreeNode* cur = q.front();
                q.pop();

                if(itr == size-1) res.push_back(cur->val);

                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
        }
       return res;
    }
};
