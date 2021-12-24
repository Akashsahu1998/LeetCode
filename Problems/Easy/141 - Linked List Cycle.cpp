
// Question) 141. Linked List Cycle


// Implementation

// Using slow & fast pointers
// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
