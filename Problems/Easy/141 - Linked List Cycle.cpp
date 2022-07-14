
// Question) 141. Linked List Cycle


// Implementation

// 1st Approach
// Using slow & fast pointers
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next && slow != fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow == fast;
    }
};


// 2nd Approach
// Using slow & fast pointers
// Time Complexity = O(N)
// Space Complexity = O(1)

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
