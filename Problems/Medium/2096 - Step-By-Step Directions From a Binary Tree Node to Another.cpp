
// Question) 2096. Step-By-Step Directions From a Binary Tree Node to Another


// Implementation

// Using LCA Technique, DFS
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
private:
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(!root) return NULL;
        
        if(root->val == startValue || root->val == destValue){
            return root;
        }
        
        TreeNode* leftLCA = findLCA(root->left, startValue, destValue);
        TreeNode* rightLCA = findLCA(root->right, startValue, destValue);
        
        if(leftLCA && rightLCA){
            return root;
        }
        
        return leftLCA ? leftLCA : rightLCA;
    }
    
    bool findNode(TreeNode* root, int startValue, string &url){
        if(!root) return false;
        
        if(root->val == startValue) return true;
        
        // trying to finding the node on left side
        url += 'L';
        
        // if found
        if(findNode(root->left, startValue, url)){
            return true;
        }        
        // if not found, so Backtrack
        url.pop_back();
        
        // trying to finding the node on right side
        url += 'R';
        
        // if found
        if(findNode(root->right, startValue, url)){
            return true;
        }        
        // if not found, so Backtrack
        url.pop_back();
        
        // if node not found anywhere
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        // finding LCA
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        // finding the startURL from LCA for startValue and destinationURL from LCA for destValue
        string startURL = "", destinationURL = "";
        findNode(lca, startValue, startURL);
        findNode(lca, destValue, destinationURL);
        
        // In the starting we are going left side, so the time when we will find the startvalue on left side, so if we will start from their then it will be look like up side, so thats why assigning U to the startURL.
        for(auto &ch : startURL){
            ch = 'U';
        }
        
        return startURL + destinationURL;
    }
};
