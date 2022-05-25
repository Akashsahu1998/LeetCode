
// Question) 297. Serialize and Deserialize Binary Tree


// Implementation


// 1st Approach
// Using DFS
// Time Complexity = O(N)
// Space Complexity = O(N)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream s(data);
        return deserializeTheData(s);
    }
    
   // Helper function to deserialize the Data which is in string format.
   TreeNode* deserializeTheData(stringstream &s){
       string str;
       getline(s, str, ' ');
       if(str == "#") return NULL;
       else{
           TreeNode* root = new TreeNode(stoi(str));
           root->left = deserializeTheData(s);
           root->right = deserializeTheData(s);
           return root;
        }
   }
};


// 2nd Approach
// Level Order Traversal
// Using Queue
// Time Complexity = O(N)
// Space Complexity = O(N)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node) res.append(to_string(node->val) + ',');
            else res.append("#,");
            
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string str;
        
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str != "#"){
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(s,str,',');
            if(str != "#"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
