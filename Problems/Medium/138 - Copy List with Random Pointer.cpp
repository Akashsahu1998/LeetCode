
// Question) 138. Copy List with Random Pointer


// Implementation

// Naive Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* copy = new Node(0);
        Node* cur = head;
        Node* copyCur = copy;
        
        // buidling the next pointer for copy list &
        // pushing into map with the pair org node and copy node
        unordered_map<Node*, Node*> mp;
        while(cur){
            copyCur->next = new Node(cur->val);
            mp[cur] = copyCur->next;
            cur = cur->next;
            copyCur = copyCur->next;
        }
        
        // again pointing cur to head &
        // copycur to copynext, bcz now we need to build random pointer also
        cur = head;
        copyCur = copy->next;
        
        // buidling the random pointer for copy list
        // from the map key value
        // key = org, value = copy(which we created)
        while(cur){
            if(cur->random){
                copyCur->random = mp[cur->random];
            }
            cur = cur->next;
            copyCur = copyCur->next;
        }
        
        return copy->next;
    }
};
