
// Question) 380. Insert Delete GetRandom O(1)


// Implementation

// Using Unordered Map & Vector
// Time Complexity = O(1)
// Space Complexity = O(N)

class RandomizedSet {
private:
    
    // using vector, bcz by rand() we will get the index, and by that index we need to return the value as well
    vector<int> arr;
    
    // value & index(size of the arr)
    unordered_map<int, int> mp;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        
        mp[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        
        int lastValueOfArr = arr.back();
        int index = mp[val];
        arr[index] = lastValueOfArr;
        mp[lastValueOfArr] = index;
        
        arr.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
