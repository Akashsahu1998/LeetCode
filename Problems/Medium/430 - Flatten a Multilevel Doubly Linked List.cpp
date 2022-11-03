
// Question) 430. Flatten a Multilevel Doubly Linked List


// Implementation

// Iterative Solution
// Time Complexity = O(N),
// Space Complexity = O(1), no Space used, we just created few pointers, but they are pointing, they are not storing anything 
class Solution {
public:
    Node* flatten(Node* head) {
        Node *ptr = head, *curr = NULL, *storedNode = NULL;
        
        // ptr will iterate through each element
        while(ptr){
            
            // if child is there, then go inside it.
            if(ptr->child){
                // store the node
                storedNode = ptr->next;
                
                // assign the child to its next
                ptr->next = ptr->child;
                
                // assign the prev to itself
                ptr->next->prev = ptr;
                
                // put NULL into child, bcz not its ended
                ptr->child = NULL;
                
                // take curr from ptr->next
                curr = ptr->next;
                
                // run till the last, bcz we need to assign storedNode into cur last node
                while(curr->next){
                    curr = curr->next;
                }
                
                // assigning the storeNode into the curr last node
                curr->next = storedNode;
                
                // if next is there, it means storedNode was there, then assign the curr(itself) as the prev node
                if(curr->next){
                    curr->next->prev = curr;
                }
            }
            
            // always move ptr by 1 step
            ptr = ptr->next;
        }
        
        // return head as result
        return head;
    }
};
