
// Question) 146. LRU Cache


// Implementation

// Using doubly linked list & unordered_map
// Time Complexity = O(1), Space Complexity = O(N)
class LRUCache {
public:
    int size;    
    
    class ListNode{
    public:
        int key, val;
        ListNode *prev, *next;

        ListNode(int k, int v){
            key = k;
            val = v;            
        }
    };
    
    // head->next will hold the recently added node
    ListNode *head = new ListNode(-1, -1);
    
    // tail->prev will hold the old added node
    ListNode *tail = new ListNode(-1, -1);
    unordered_map<int, ListNode*> mp;    
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(ListNode *newNode){
        ListNode* temp = head->next;        
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(ListNode *delNode){
        ListNode *delNodePrev = delNode->prev;
        ListNode *delNodeNext = delNode->next;
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;        
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            // holding the existing result node
            ListNode *resNode = mp[key];
            int res = resNode->val;
            
            // delete from map
            mp.erase(key);
            
            // delete the node
            deleteNode(resNode);
            
            // add the node, so it will be recently added node
            addNode(new ListNode(key, res));
            
            // add the key again into map with new address
            mp[key] = head->next;  
                
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // holding the existing node
            ListNode *temp = mp[key];
            
            // delete from map
            mp.erase(key);
            
            // delete the node
            deleteNode(temp);
        }
        if(mp.size() == size){
            // holding the existing node
            ListNode *temp = tail->prev;
            
            // delete from map            
            mp.erase(temp->key);
            
            // delete the node
            deleteNode(temp);
        }
        
        // add the node, so it will be recently added node
        addNode(new ListNode(key, value));
        
        // add the key again into map with new address
        mp[key] = head->next;
    }
};
