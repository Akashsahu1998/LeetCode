
// Question) 1021. Remove Outermost Parentheses

// Implementation
// Time Complexity = O(n)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int itr = 0, outerParanthesis = 0;
        string res = "";
        while(itr != s.size()){
            if(s[itr] == '(') outerParanthesis++;
            
            if(outerParanthesis > 1){
                if(s[itr] == ')') outerParanthesis--;               
                res = res + s[itr];
            }
            else if(s[itr] == ')') outerParanthesis--;            
            itr++;
        }
        
        return res;
    }
};

