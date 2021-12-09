
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


// Recursive Approach
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;
        for(int itr = 0; itr < k; itr++){
            if(!node) return head;
            node = node->next;
        }
        
        ListNode *cur = head, *prev = NULL, *nex = NULL;        
        for(int itr = 0; itr < k; itr++){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};
