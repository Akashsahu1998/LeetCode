
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
