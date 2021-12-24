
// Question) 19. Remove Nth Node From End of List


// Implementation

// movign the ptr1 n steps ahead of ptr2,
// so when ptr1 reaches null it means ptr2 will be
// standing on a nth node from last
// and will be mainting the prev and next ptr of ptr1

// using two pointer, next and prev
// Single Traversal
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	// if only one node is there into list, them simply return null
        if(!head->next) return NULL;
        ListNode *ptr1 = head, *ptr2 = head, *prev = NULL, *nextt = head->next;
        
        while(ptr1){
            if(n > 0){
                ptr1 = ptr1->next;
                n--;
            }
            else{                
                ptr1 = ptr1->next;
                prev = ptr2;
                ptr2 = ptr2->next;
                nextt = ptr2->next;
            }
        }
        
        if(prev){
            prev->next = nextt;
        }
        else head = nextt;
            
        return head;
    }
};
