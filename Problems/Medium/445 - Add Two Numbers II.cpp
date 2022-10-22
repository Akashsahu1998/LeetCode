
// Question) 445. Add Two Numbers II


// Implementation

// Not reversing input
// Time Complexity = O(max(N1, N2)), where N1 = l1.size(), N2 = l2.size()
// Space Complexity = O(1), not considering head because thats a part of output

class Solution {
private:
    int getSize(ListNode* list){
        int size = 0;        
        while(list){
            list = list->next;
            size++;
        }        
        return size;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int n1 = getSize(l1);
        int n2 = getSize(l2);
        
        ListNode *head = NULL;
        while(l1 || l2){
            int val = 0;
            
            if(n1 >= n2){
                val += l1->val;
                l1 = l1->next;
                n1--;
            }
            
            if(n1 < n2){
                val += l2->val;
                l2 = l2->next;
                n2--;
            }
            
            ListNode *cur = new ListNode(val);
            cur->next = head;
            head = cur;
        }
        
        l1 = head;
        head = NULL;
        int carry = 0;
        while(l1){
            int val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            
            ListNode *cur = new ListNode(val);
            cur->next = head;
            head = cur;
            
            l1 = l1->next;
        }
        
        if(carry){
            ListNode *cur = new ListNode(carry);
            cur->next = head;
            head = cur;
        }
        
        return head;
    }
};
