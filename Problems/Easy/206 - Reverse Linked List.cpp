
// Question) 206. Reverse Linked List


// Implementation

// Iterative Approach
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


// Recursive Approach
// Time Complexity = O(N), Space Complexity = O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};
