
// Question) 83. Remove Duplicates from Sorted List


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur){            
            if(cur->next && cur->next->val == cur->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};
