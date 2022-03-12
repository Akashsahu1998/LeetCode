
// Question) 1347. Minimum Number of Steps to Make Two Strings Anagram


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(N)
// Here we are using 2 maps
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

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(N)
// Here we are using only 1 map
class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0, itr = 0, jtr = 0;
        unordered_map<char, int> mp;        
        
        while(itr < s.length()){
            mp[s[itr++]]++;
            mp[t[jtr++]]--;            
        }
        
        for(auto ch: mp){
            if(ch.second < 0) count += ch.second;
        }
        return abs(count);
    }
};


// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(N)
// Here we are using only 1 map, counting the unmatched char
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        
        for(auto ch : s) mp[ch]++;
        
        int unmatchChar = 0;
        for(auto ch : t){
            if(mp[ch]){
                mp[ch]--;
            }
            else unmatchChar++;
        }
        
        return unmatchChar;
    }
};
