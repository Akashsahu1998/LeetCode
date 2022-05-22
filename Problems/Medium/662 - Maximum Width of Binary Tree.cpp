
// Question) 662. Maximum Width of Binary Tree


// Implementation

// Using Queue, Level Order Traversal
// Time Compelxity : O(N)
// Space Compelxity : O(N)

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long>> q;        
        q.push({root, 0});
        
        int res = -1;
        while(!q.empty()){
            
            int size = q.size();
            int minValue = q.front().second;
            int first, last;
            
            for(int i = 0; i < size; i++){
                long curVal = q.front().second - minValue;
                
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0) first = curVal;
                if(i == size-1) last = curVal;
                
                if(node->left) q.push({node->left, curVal*2+1});
                if(node->right) q.push({node->right, curVal*2+2});
            }
            
            res = max(res, last - first + 1);
        }
        
        return res;
    }
};
