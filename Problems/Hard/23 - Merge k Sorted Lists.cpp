
// Question) 23. Merge k Sorted Lists


// Implementation

// 1st Approach
// Not an Efficient Method
// Time Complexity = O(N * max(k.length))
// Space Complexity = O(max(k.length)), bcz of the recursive mergeTwoLists function

// Idea : Iterating over the k lists from 1 to N, and adding all the lists into lists[0], and in last returning that lists[0], bcz all other k lists are getting merged into this lists[0]

class Solution {
private:
    // Recursive Approach to merge the sorted lists
    // Time Complexity = O(max(first, second))
    // Space Complexity = O(max(first, second)), bcz of stack trace
    ListNode* mergeTwoLists(ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;        
        
        if(first->val < second->val){
            first->next = mergeTwoLists(first->next, second);
            return first;
        }
        else{
            second->next = mergeTwoLists(first, second->next);
            return second;
        }
    }
    
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        // traversing over the lists
        for(int itr = 1; itr < lists.size(); itr++){
            lists[0] = mergeTwoLists(lists[0], lists[itr]);
        }
        
        return lists[0];
    }
};
