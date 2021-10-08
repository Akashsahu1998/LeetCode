
// Question) 297. Serialize and Deserialize Binary Tree


// Implementation

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree.
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
