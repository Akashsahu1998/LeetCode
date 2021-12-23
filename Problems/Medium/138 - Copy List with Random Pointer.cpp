
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


// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        // Building the dummyNode after each and every original node(cur)
        // pointing the cur->next to dummyNode & dummyNode to cur->next->next
        Node *cur = head;        
        while(cur){
            Node *front = cur->next;
            Node *dummyNode = new Node(cur->val);
            cur->next = dummyNode;
            dummyNode->next = front;
            cur = front;
        }
        
        // Pointing the randomNode in each and every dummy node we created
        cur = head;
        while(cur){
            if(cur->random){
                // we are putting random node(cur->random->next) in dummyNode(cur->next->random) only
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // Pointing the copy to the first dummy node, so we can return it.
        cur = head;
        Node* copy = new Node(0);
        Node* copyCur = copy;
        
        // deleting the links of org nodes to dummy nodes
        while(cur){            
            copyCur->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            copyCur = copyCur->next;
        }
        
        return copy->next;
    }
};
// https://www.youtube.com/watch?v=VNf6VynfpdM
