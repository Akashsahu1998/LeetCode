
// Question) 160. Intersection of Two Linked Lists


// Implementation

// 1st Approach
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


// 2nd Approach
// Efficient Approach
// Idea is to iterate over each list two times
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;

        // For example
        // headA = [1, 2, 3, 4]
        // headB = [8, 4]
        // Just assume it as headA = headA + headB, and headB = headB + headA
        // headA = [1, 2, 3, 4, 8, 4]
        // headB = [8, 4, 1, 2, 3, 4]
        // we are iterating in this way
        
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
    }
};
