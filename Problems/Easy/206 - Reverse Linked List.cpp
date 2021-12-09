
// Question) 206. Reverse Linked List206. Reverse Linked List


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        ListNode* prev = NULL;
        ListNode* next = NULL;        
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
