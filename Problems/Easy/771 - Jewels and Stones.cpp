
// Question) 771. Jewels and Stones


// Implementation

// 1st Approach in C++
// Time Complexity = O(jewels.size() + stones.size()), Space Complexity = O(jewels.size())

int numJewelsInStones(string jewels, string stones) {
    int count = 0;
    unordered_set<char> setJewels(jewels.begin(), jewels.end());
    for(char ch : stones){
        if(setJewels.find(ch) != setJewels.end()) count++;  
    }
    return count;
}


// 2nd Approach in Java
// Time Complexity = O(jewels.length() + stones.length()), Space Complexity = O(jewels.length())

public int numJewelsInStones(String jewels, String stones) {
    int count = 0;        
    Set setJewels = new HashSet();
    for(int itr = 0; itr < jewels.length(); itr++)
        setJewels.add(jewels.charAt(itr)); 
    
    for(int itr = 0; itr < stones.length(); itr++){
        if(setJewels.contains(stones.charAt(itr))) count++;  
    }
    return count;
}
