
// Question) 856. Score of Parentheses


// Implementation

// 1st Approach
// using stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for(auto itr : s){
            // if meets this '(' then just add 0 to stack
            if(itr == '('){
                st.push(0);
            }
            else{
                // if we meets ')' then take out the top value, and
                // check if its 0 then simply add 1 to the next top of the stack, or
                // if its more than 0 it means we are already in one inside the level, then
                // simply multiply that value by 2, and add it into the next top of the stack
                int val = st.top();
                st.pop();
                int newValue = 0;
                if(val){
                    newValue = val * 2;
                }
                else{                    
                    newValue = 1;
                }
                st.top() += newValue;                
            }
        }
        return st.top();
    }
};


// 2nd Approach
// Most Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, res = 0;
        
        for(int itr = 0; itr < s.size(); itr++){
            if(s[itr] == '(') depth++;
            else depth--;
            
            // we need to add the 2^depth, when we are getting any pair like ()
            if(s[itr] == ')' && s[itr-1] == '('){
                res += pow(2, depth);
            }            
        }
        return res;
    }
};
