
// Question) 20. Valid Parentheses


// Implementation

// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        int itr = 0;
        
        while(itr < str.size()){
            if(s.empty()){
                s.push(str[itr]);
            }
            else{
                if(str[itr] == '}' && s.top() == '{') s.pop();
                else if(str[itr] == ']' && s.top() == '[') s.pop();
                else if(str[itr] == ')' && s.top() == '(') s.pop();
                else s.push(str[itr]);
            }
            itr++;
        }
        
        if(s.empty()) return true;
        return false;
    }
};
