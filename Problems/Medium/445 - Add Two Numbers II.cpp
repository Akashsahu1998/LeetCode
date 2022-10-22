
// Question) 445. Add Two Numbers II


// Implementation

// LC Solution : https://leetcode.com/problems/add-two-numbers-ii/discuss/2733150/3-Approaches-2-Follow-Up-Comments-Added-Without-reversing-input-C%2B%2B

// Approach - 1
// Reverse the Input
// Time Complexity = O(N1 + N2), where N1 = l1.size(), N2 = l2.size()
// Space Complexity = O(1)


// Follow up: Could you solve it without reversing the input lists ?


// Approach - 2
// Using 2 Stack
// Time Complexity = O(N1 + N2), where N1 = l1.size(), N2 = l2.size()
// Space Complexity = O(max(N1, N2), will be using the extra space


// Follow up: Could you come up with O(1) Space Solution in without reversing the input ?


// Approach - 3
// Not reversing input
// Time Complexity = O(N1 + N2), where N1 = l1.size(), N2 = l2.size()
// Space Complexity = O(1), not considering head because thats a part of output

class Solution {
private:
    // finding the length of the list 
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
        
        // collecting the size of both given lists
        int n1 = getSize(l1);
        int n2 = getSize(l2);
        
        // will be storing the result into this head list
        ListNode *head = NULL;
        
        // adding the value of l1 and l2 in place, and reversing the result
        // l1 = 9->4->4->3
        // l2 =    5->6->7
        // head = 9->9->10->10
        // after reversing => 10->10->9->9
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
            
            // update the head (basically reversing the list as well)
            // add new node to front
            ListNode *cur = new ListNode(val);
            cur->next = head;
            head = cur;
        }
        
        // reusing l1
        l1 = head;
        
        // point head to NULL, because again we need to reverse it, to make it in a original state
        // also manage all the carry values
        head = NULL;
        int carry = 0;
        while(l1){
            int val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            
            // update the head (basically reversing the list as well)
            // add new node to front
            ListNode *cur = new ListNode(val);
            cur->next = head;
            head = cur;
            
            // moving l1 one step ahead
            l1 = l1->next;
        }
        
        // if there is any carry, take care of that edge case as well
        if(carry){
            ListNode *cur = new ListNode(carry);
            cur->next = head;
            head = cur;
        }
        
        // returning result
        return head;
    }
};

// Algo Step's
// 1) Not reverse the input, but reverse the output
// 2) find the sum of l1 & l2 list values inplace, and reverse
// 3) later manage the carry part and again reverse
