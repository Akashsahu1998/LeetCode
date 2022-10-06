
// Question) 101. Symmetric Tree


// Implementation

// Recursive/DFS Approach 
// Time Complexity = O(N)
// Space Complexity = O(H) where H is the height of the Binary Tree

bool checkIsSymmetric(TreeNode* r1, TreeNode* r2) {
    // if both are null
    if(!r1 && !r2) return true;
    
    // if anyone is null and another one is not null
    if(!r1 || !r2) return false;
    
    // checking if value are equal or not
    return (r1->val == r2->val) && checkIsSymmetric(r1->left, r2->right) && checkIsSymmetric(r1->right, r2->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return (checkIsSymmetric(root->left, root->right));        
}


// Iterative/BFS Approach
// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the Binary Tree
bool checkIsSymmetric(TreeNode* r1, TreeNode* r2) {
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL || r2 == NULL) return false;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(r1);
    q2.push(r2);
    while(q1.empty() == false && q2.empty() == false){
        if(q1.size() != q2.size()) return false;
        TreeNode* cur1 = q1.front();
        q1.pop();
        TreeNode* cur2 = q2.front();
        q2.pop();
        
        if(cur1==NULL && cur2==NULL) continue;
        if(cur1==NULL && cur2!=NULL) return false;
        if(cur1!=NULL && cur2==NULL) return false;
        
        if(cur1->val != cur2->val) return false;
        
        if(cur1->left != NULL) q1.push(cur1->left);                
        else q1.push(NULL);
        if(cur1->right != NULL) q1.push(cur1->right);
        else q1.push(NULL);
        
        if(cur2->right != NULL) q2.push(cur2->right);                
        else q2.push(NULL);
        if(cur2->left != NULL) q2.push(cur2->left);
        else q2.push(NULL);
    }
     return (q1.size() == q2.size());
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return (checkIsSymmetric(root->left, root->right));        
}
