
// Question) 460. LFU Cache


// Implementation

// Using Unordered Map & Doubly Linked List
// Time Complexity : O(1)
// Space Complexity : O(N)

struct Node{
    int cnt, val, key;
    Node* next;
    Node* prev;
    
    Node(int _key, int _val){
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNodeIntoList(Node* node){
        Node* temp = head->next;
        
        node->next = temp;
        node->prev = head;
        
        head->next = node;
        temp->prev = node;
        
        size++;
    }
    
    void removeNodeFromList(Node* delnode){        
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
        
        size--; 
    }    
};

class LFUCache {
private:
    int minFreqInMap, size, curSize;
    
    // frequency, list for that frequency
    unordered_map<int, List*> mapFreqList;
    
    // key, nodeAddress
    unordered_map<int, Node*> keyNodeMap;
    
public:
    LFUCache(int capacity) {
        size = capacity;
        curSize = 0;
        minFreqInMap = 0;
    }
    
    void updateFreqOfNodeIntoFreqListMap(Node* node){
        keyNodeMap.erase(node->key);
        mapFreqList[node->cnt]->removeNodeFromList(node);
        
        if(node->cnt == minFreqInMap && mapFreqList[node->cnt]->size == 0){
            minFreqInMap++;
        }
        
        List* list = new List();
        if(mapFreqList[node->cnt + 1]){
            list = mapFreqList[node->cnt + 1];
        }
        
        node->cnt += 1;
        list->addNodeIntoList(node);
        mapFreqList[node->cnt] = list;
        keyNodeMap[node->key] = node;
    }
    
    int get(int key) {        
        if(keyNodeMap[key]){
            Node* node = keyNodeMap[key];
            int value = node->val;
            updateFreqOfNodeIntoFreqListMap(node);
            return value;
        }        
        return -1;
    }
    
    void put(int key, int value) {
        
        // edge case
        if(size == 0) return;
        
        if(keyNodeMap[key]){
            Node* node = keyNodeMap[key];
            node->val = value;
            updateFreqOfNodeIntoFreqListMap(node);
        }
        else{
            if(size == curSize){
                List* list = mapFreqList[minFreqInMap];
                keyNodeMap.erase(list->tail->prev->key);
                mapFreqList[minFreqInMap]->removeNodeFromList(list->tail->prev);
                curSize--;
            }
            
            curSize++;
            minFreqInMap = 1;
            
            List* list = new List();
            if(mapFreqList[minFreqInMap]){
                list = mapFreqList[minFreqInMap];
            }
            
            Node* node = new Node(key, value);
            list->addNodeIntoList(node);
            mapFreqList[minFreqInMap] = list;
            
            keyNodeMap[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
