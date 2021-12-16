
// Question) 82. Remove Duplicates from Sorted List II


// Implementation

// Iterative Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {      
        ListNode *res = new ListNode();
        res->next = head;
        ListNode *cur = res;        
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                ListNode* temp = cur->next;
                while(cur->next && temp->val == cur->next->val){
                    cur->next = cur->next->next;
                }
            }
            else{
                cur = cur->next;
            }            
        }
        return res->next;
    }
};
