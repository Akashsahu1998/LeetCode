
Q1.) 1614. Maximum Nesting Depth of the Parentheses

class Solution {
public:
    int maxDepth(string S) {        
        int Max = 0, count = 0, itr;
        for(itr = 0; itr < S.size(); itr++){
            if(S[itr] == '(') count++;
            else if(S[itr] == ')') count--;
            Max = max(Max, count);
        }
        return Max;
    }
};
