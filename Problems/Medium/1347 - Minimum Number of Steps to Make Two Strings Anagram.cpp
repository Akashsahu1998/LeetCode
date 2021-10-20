
// Question) 1347. Minimum Number of Steps to Make Two Strings Anagram


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        unordered_map<char, int> ump1, ump2;
        
        int itr = 0, jtr = 0;
        while(itr < s.length()){
            ump1[t[itr++]]++;
            ump2[s[jtr++]]++;
        }
        
        for(auto ch: ump1){            
            if(ump2[ch.first]){
                if(ump2[ch.first] < ch.second) count += ch.second - ump2[ch.first];
            }
            else count += ch.second;
        }
        return count;
    }
};
