
// Question) 716. Max Stack


// Implementation

// https://www.youtube.com/watch?v=BcZzdkvCQ0s

// Using Doubly Linked List & Map
// Time Complexity : O(LogN)
// Space Complexity : O(N)

class MaxStack {
private:
    // will store the key and the reference of the node into the vector, taking vector bcz there can be multiple numbers as well
    // taking this (list<int>::iterator>) bcz, we need to store the reference of the DLL
    map<int, vector<list<int>::iterator>> mp;
    // doubly linked list
    list<int> dll;
    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.push_back(x);
        // --end(dll) will give the reference of the last inserted element, and pushing into the key
        mp[x].push_back(--end(dll));
    }
    
    int pop() {
        int topValue = top();
        
        // delete the last inserted element from DLL
        dll.pop_back();
        
        // pop the last inserted reference from the vector for that particular key(topValue)
        mp[topValue].pop_back();
        
        // check if that key have empty vector then also erase that key from the map
        if(mp[topValue].empty()) mp.erase(topValue);
        return topValue;
    }
    
    int top() {
        // will return the last element
        return *rbegin(dll);
    }
    
    int peekMax() {
        // value from last
        return rbegin(mp)->first;
    }
    
    int popMax() {
        int maxValue = peekMax();
        auto referenceOfMaxValue = mp[maxValue].back();
        
        // erase the reference(referenceOfMaxValue) from DLL
        dll.erase(referenceOfMaxValue);
        
        // pop the last inserted reference from the vector for that particular key(maxValue)
        mp[maxValue].pop_back();
        
        // check if that key have empty vector then also erase that key from the map
        if(mp[maxValue].empty()) mp.erase(maxValue);
        return maxValue;
    }
};




/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
