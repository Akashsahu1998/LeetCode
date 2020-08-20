
// Time Complexity = O(n)

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *head1, *head2, *previousNode, *currentNode;       
        
        if(!head || !(head -> next)) return;  // if list contains only one element or its empty       
        else{                                  // list does not empty & it contains more than one element
            head1 = head;
            head2 = head -> next;

            // finding the starting point of the second half
            while(head2 && head2->next){
                head1 = head1 -> next;
                head2 = (head2 -> next) -> next;
            }

            //reverse the second half
            head2 = head1 -> next; // the head of the second half
            head1 -> next = NULL;
            previousNode = NULL;

            while(head2){
                currentNode = head2 -> next;
                head2 -> next = previousNode;
                previousNode = head2;
                head2 = currentNode;
            }

            // merging the first half and the reversed second half
            head2 = previousNode;
            head1 = head;

            while(head2){
                currentNode = head1 -> next;
                head1 -> next = head2;
                head1 = head1 -> next;
                head2 = currentNode;
            }            
        }
        return;
    }
};
