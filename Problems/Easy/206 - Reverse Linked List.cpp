
// Question) 206. Reverse Linked List


// Implementation

// 1st Approach
// Recursive Approach
// Time Complexity : O(N)
// Space Complexity : O(N), bcz of the recursion stack trace
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


// 2nd Approach
// Iterative Approach
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* prev = NULL;
        
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        
        return prev;
    }
};


