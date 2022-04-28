
// Question) 206. Reverse Linked List


// Implementation

// 1st Approach
// Using DFS
// Time Complexity : O(N)
// Space Complexity : O(1)
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
// Using BFS
// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* prev = NULL;
        
        while(head && head->next){
            ListNode* temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        
        head->next = prev;        
        return head;
    }
};
