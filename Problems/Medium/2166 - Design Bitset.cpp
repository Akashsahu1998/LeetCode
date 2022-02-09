
// Question) 2166. Design Bitset


// Implementation

// Using unordered set
// Time Complexity = O(1) for all functions, except toString() -> (O(N))
// Space Complexity = O(N)

class Bitset {
public:
    int size;
    unordered_set<int> onee, zero;
    
    Bitset(int size) {
        this->size = size;        
        for(int itr = 0; itr < size; itr++) zero.insert(itr); 
    }
    
    void fix(int idx) {
        onee.insert(idx);
        zero.erase(idx);
    }
    
    void unfix(int idx) {
        onee.erase(idx);
        zero.insert(idx);
    }
    
    void flip() {
        swap(onee, zero);
    }
    
    bool all() {
        return (onee.size() == size);
    }
    
    bool one() {
        return (onee.size() >= 1);
    }
    
    int count() {
        return onee.size();
    }
    
    string toString() {
        string str = "";        
        for(int itr = 0; itr < size; itr++){
            str += (onee.find(itr) != onee.end()) ? '1' : '0';
        }
        return str;
    }
};
