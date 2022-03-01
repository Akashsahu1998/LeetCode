
// Question) 2186. Minimum Number of Steps to Make Two Strings Anagram II


// Implementation

// Using Unordered Map
// Time Complexity: O(N)
// Time Complexity: O(N)
class Solution {
public:
    int minSteps(string s, string t) {
        
        // store the frequency of the char's of s string into mp
        unordered_map<char, int> mp;
        for(auto ch : s) mp[ch]++;
        
        // count the char of target string which are matching to s string
        int matchChar = 0;
        for(auto ch : t){
            if(mp[ch]) {
                mp[ch]--;
                matchChar++;
            }
        }
        
        // find how many char's of target string are there which are not matching with the char's of s string
        int unMatchCharInTarget = t.size() - matchChar;
        
        // subtract match char from s string and add the unMatchCharInTarget, then we can get the total number of char's needed to make both s & target string anagram
        int charWeNeed = (s.size() - matchChar) + unMatchCharInTarget;
        
        // return the result
        return charWeNeed;
    }
};
