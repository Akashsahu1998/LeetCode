
// Question) 921. Minimum Add to Make Parentheses Valid


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBracketCount = 0, res = 0;
        for(auto ch : s){
            (ch == '(') ? openBracketCount++ : openBracketCount--;
            if(openBracketCount < 0){
                res += abs(openBracketCount);
                openBracketCount = 0;
            }
        }
        return res + abs(openBracketCount);        
    }
};
