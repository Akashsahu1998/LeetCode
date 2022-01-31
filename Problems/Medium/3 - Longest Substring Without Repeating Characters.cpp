
// Question) 2155. All Divisions With the Highest Score of a Binary Array


// Implementation

// Using window sliding technique
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N), it will have maximum no. of unique element into current window 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxCount = 0, curCount = 0;
        
        // iterating over the string
        // using itr & jtr to track current window in which, we which we are having unique element
        for(int itr = 0, jtr = 0; itr < s.size(); itr++){
            
            // get the current char
            char ch = s[itr];
            
            // if current char is present into map, then delete all key till that already present char, and decrease the count
            if(mp[ch]){
                while(s[jtr] != ch){
                    mp[s[jtr]]--;
                    curCount--;
                    jtr++;
                }
                
                mp[s[jtr]]--;
                curCount--;
                jtr++;                
            }
            
            // add the current char in last, and incr the count, bcz now that char is going to add into the map
            mp[ch]++;
            curCount++;            
            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};
