
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
