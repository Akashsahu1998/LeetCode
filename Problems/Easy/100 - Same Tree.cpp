
// Question) 100. Same Tree


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = (O(W)+O(W)) = O(W) where W is the width of the Binary Tree

bool isSameTree(TreeNode* p, TreeNode* q) {        
    
    if(p != NULL && q != NULL){
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        
        pq.push(p);
        qq.push(q);
        
        while(pq.empty() == false && qq.empty() == false){
            TreeNode* cur1 = pq.front(); pq.pop();
            TreeNode* cur2 = qq.front(); qq.pop();
            
            if(cur1->val != cur2->val) return false;
                                            
            if(cur1->left != NULL && cur2->left != NULL) {
                pq.push(cur1->left);
                qq.push(cur2->left);
            }
            else if(cur1->left != cur2->left) return false;
            
            if(cur1->right != NULL && cur2->right != NULL){
                pq.push(cur1->right);
                qq.push(cur2->right);
            }
            else if(cur1->right != cur2->right) return false;
        }            
        if(pq.empty() != qq.empty()) return false;
        else return true;
    }
    else if(q != p) return false; 
    else return true;
}
