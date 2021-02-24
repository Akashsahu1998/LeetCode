
// Question) 1207. Unique Number of Occurrences


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> ump;
    unordered_map<int, int> ump2;
    
    for(auto a : arr) ump[a]++;            
    
    for(auto a : ump) ump2[a.second]++;            
    
    for(auto a : ump2){
        if(a.second > 1) return false;
    }            
    return true;        
}
