
// Question) 2. Add Two Numbers


// Implementation

// Time Complexity = O(max(l1, l2)), Space Complexity = O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL, *cur = NULL;
        int carry = 0;
        while(l1 || l2){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = (sum > 9) ? 1 : 0;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            if(res == NULL) res = temp;
            else cur->next = temp;
            cur = temp;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry){
            ListNode *temp = new ListNode(carry);
            cur->next = temp;
            cur = temp;
        }
        return res;
    }
};