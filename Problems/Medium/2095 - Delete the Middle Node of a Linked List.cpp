
// Question) 2095. Delete the Middle Node of a Linked List


// Implementation

// Fast, Slow & Prev Pointer
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;        
        return head;
    }
};
