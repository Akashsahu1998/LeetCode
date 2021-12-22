
// Question) 61. Rotate List


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // if list size is 0 or 1 or k is 0 then return head
        if(!head || !head->next || k == 0) return head;
        
        // Finding the length
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        
        // k can be greater than length that's why doing mod by length
        k = k%len;
        
        // calculating the k, so we can shift k elements to the right
        k = len - k;
        
        cur = head;
        ListNode* prev = NULL;
        
        // running till the starting k elements by maintaining prev
        while(cur && k--){
            prev = cur;
            cur = cur->next;
        }
        
        // if length and k is same
        if(!cur) return head;
        
        // prev will contain the last element
        ListNode* returnValue = cur;
        prev->next = NULL;
        
        // going till the last
        while(cur->next){
            cur = cur->next;
        }
        
        // pointing last element next to head.
        cur->next = head;
        return returnValue;        
    }
};
