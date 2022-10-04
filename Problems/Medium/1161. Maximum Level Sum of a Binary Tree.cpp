
// Question) 1161. Maximum Level Sum of a Binary Tree


// Implementation


// Using BFS/Queue
// Iterative Solution
// Time Complexity = O(N)
// Space Complexity = O(N)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curLevel = 1, maxLevel = 1, maxSum = root->val;
        
        while(!q.empty()){
            int size = q.size(), sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(sum > maxSum){
                maxLevel = curLevel;
                maxSum = sum;
            }
            curLevel++;
        }
        
        return maxLevel;
    }
};
