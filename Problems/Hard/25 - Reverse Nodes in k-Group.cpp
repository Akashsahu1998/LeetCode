
// Question) 25. Reverse Nodes in k-Group


// Implementation

// Iterative Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *cur = dummy, *pre = dummy, *nex = dummy;
        int count = 0;
        
        while(cur->next){
            cur = cur->next;
            count++;
        }
        
        while(count >= k){
            cur = pre->next;
            nex = cur->next;
            
            for(int itr = 1; itr < k; itr++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            
            pre = cur;
            count -= k;
        }
        
        return dummy->next;
    }
};
