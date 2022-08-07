
// Question) 876. Middle of the Linked List


// Implementation


// Using Slow & Fast Pointer
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* slow) {
        ListNode* fast = slow;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
