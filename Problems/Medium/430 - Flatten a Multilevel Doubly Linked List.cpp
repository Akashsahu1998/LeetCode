
// Question) 430. Flatten a Multilevel Doubly Linked List


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        Node *ptr = head, *cur = NULL, *storedNode = NULL;
        
        while(ptr){
            if(ptr->child){
                // storing the ptr->next, and pointing the ptr next to child
                storedNode = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;                
                ptr->child = NULL;
                
                // running till the end of the child list
                cur = ptr->next;
                while(cur->next){
                    cur = cur->next;
                }
                
                // connect the storedNode at the last of the child list
                cur->next = storedNode;
                if(cur->next){
                    cur->next->prev = cur;
                }
            }
            ptr = ptr->next;
        }
        return head;
    }
};
