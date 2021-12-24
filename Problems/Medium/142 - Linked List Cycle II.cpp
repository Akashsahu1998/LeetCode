
// Question) 142. Linked List Cycle II


// Implementation

// Using two ptr
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        // find cycle is there or not
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        // no cycle
        if(!fast || !fast->next || !slow) return NULL;
                
        // start slow again from head
        slow = head;        
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;  // move fast also as a slow ptr
        }
        
        return fast;
    }
};
