
// Question) 160. Intersection of Two Linked Lists


// Implementation

// Naive Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        
        // Storing the Node as a key value pair
        ListNode* cur = headA;        
        while(cur){
            mp[cur]++;
            cur = cur->next;
        }
        
        // Iteratign & Checking if node is already present into map,
        // it means that is the intersection point.
        cur = headB;        
        while(cur){
            if(mp[cur]) return cur;
            cur = cur->next;
        }
        
        // if not present
        return NULL;
    }
};

// Efficient Approach
// Idea is to iterate over a list two times
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        // For example
        // headA = [1, 2, 3, 4]
        // headB = [8, 4]
        // Just assume it as
        // headA = [1, 2, 3, 4, 8, 4]
        // headB = [8, 4, 1, 2, 3, 4]
        // we are iterating in this way
        
        while(curA != curB){
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};
