
// Question) 234. Palindrome Linked List


// Implementation

// Using slow and fast pointer
// Reversing the second half
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* reverse(ListNode *dummy){
        if(!dummy) return NULL;
        ListNode* prev = NULL;
        while(dummy->next){
            ListNode *temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        dummy->next = prev;
        return dummy;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        // slow will reach to mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing all nodes after the mid node(second half)
        slow->next = reverse(slow->next);
        
        // again starting
        ListNode* start = head;
        slow = slow->next;
        
        // comparing the start and slow, and simultaneously moving one step ahead
        while(slow){
            if(slow->val != start->val) return false;
            slow = slow->next;
            start = start->next;
        }
        return true;
    }
};
