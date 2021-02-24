
// Question) 1207. Unique Number of Occurrences


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

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


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public boolean uniqueOccurrences(int[] arr) {
    HashMap<Integer, Integer> h1 = new HashMap<Integer, Integer>();
    HashMap<Integer, Integer> h2 = new HashMap<Integer, Integer>();
    
    for(int a : arr){
        if(h1.containsKey(a)) h1.put(a, h1.get(a)+1);
        else h1.put(a, 1);            
    } 
    
    for(Map.Entry<Integer, Integer> entry : h1.entrySet()){
        if(h2.containsKey(entry.getValue())) h2.put(entry.getValue(), h2.get(entry.getValue())+1);
        else h2.put(entry.getValue(), 1);            
    }
    
    for(Map.Entry<Integer, Integer> entry : h2.entrySet()){
        if(entry.getValue() > 1) return false;            
    }
    return true;
}

