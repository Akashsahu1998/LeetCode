
// Question) 382. Linked List Random Node


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode *list;
    
    Solution(ListNode* head) {
        list = head;
    }
    
    int getRandom() {
        ListNode *cur = list;
        int res = cur->val;
        
        for(int itr = 1; cur->next != NULL; itr++){
            cur = cur->next;
            if((rand()%(itr+1)) == itr) res = cur->val;
        }
        
        return res;
    }
};
