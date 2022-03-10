
// Question) 392. Is Subsequence


// Implementation

// Time Complexity : O(N), where N = t.size();
// Space Complexity : O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int itr = 0;
        
        // iterating over the t string
        for(auto ch : t){
            
            // if char matches so increase the itr by 1
            if(ch == s[itr]) itr++;
        }
        
        // if itr is equal to s.size() it means, all characters are of s string are present into t in sequencial order so return true, otherwise false
        return itr == s.size();
    }
};
