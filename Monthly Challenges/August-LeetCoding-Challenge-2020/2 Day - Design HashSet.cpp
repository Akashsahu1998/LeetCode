class MyHashSet {
public:
    /** Initialize your data structure here. */
    int array[1000009] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        array[key] = 1;
    }
    
    void remove(int key) {
        array[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(array[key]) return true;
        else return false;
    }
};

