
// Question) 21. Merge Two Sorted Lists


// Implementation

// Iterative Approach
// Time Complexity = O(max(M,N)), Space Complexity = O(1)
// class Solution {
 public:    
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode *dummy = new ListNode(0);
         ListNode *res = dummy;

         // moving both list1 & list2 until any one reaches null and
         // comparing values, bcased on that adding into dummy list
         while(list1 && list2){
             if(list1->val <= list2->val){
                 dummy->next = list1;
                 list1 = list1->next;
             }
             else{
                 dummy->next = list2;
                 list2 = list2->next;
             }
             dummy = dummy->next;
         }

         // if list1 is not empty then simply adding list1, otherwise list2
         dummy->next = list1 ? list1 : list2;

         // returning next, bcz res is pointing to 0
         return res->next;
     }
 };
