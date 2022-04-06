
// Question) 116. Populating Next Right Pointers in Each Node


// Implementation

// https://www.youtube.com/watch?v=3MRPQFUpoA0
// Iterative Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* head = root;
        
        while(root->left){
            Node* temp = root->left;
            
            do{
                root->left->next = root->right;  
                
                if(root->next){
                    root->right->next = root->next->left;                    
                }
                root = root->next;
                
            }while(root);
            
            root = temp;
        }
        
        return head;
    }
};
