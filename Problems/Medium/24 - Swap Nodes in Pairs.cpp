
// Question) 24. Swap Nodes in Pairs


// Implementation

// Using 2 Prev Pointer
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *prev1 = NULL, *prev2 = NULL;
        ListNode *cur = head;
        ListNode *nextt = cur->next;
        
        while(nextt){
            if(!prev1) head = nextt;
            prev2 = prev1;
            prev1 = cur;
            cur->next = nextt->next;
            nextt->next = prev1;
            if(prev2) prev2->next = nextt;
            cur = cur->next;
            if(!cur) break;
            nextt = cur->next;
        }
        return head;
    }
};
