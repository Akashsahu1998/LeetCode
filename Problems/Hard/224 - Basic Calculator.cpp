
// Question) 224. Basic Calculator


// Implementation

// Using Stack
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    int calculate(string s) {
        
        // will use stack to store the res & sign (for the current bracket)
        stack<int> st;
        
        // intially taking sign as 1, sign can be 1(positive) & -1(negative)
        int res = 0, sign = 1, size = s.size();
        
        // iterating over the string
        for(int i = 0; i < size; i++){
            
            // if current char is digit, then
            // collect the digit and multiply it with current sign and add into the res
            if(isdigit(s[i])){
                // taking long bcz (num * 10) in this statement there can be chance of integer overflow
                // i.e, s = "2147483647", to handle these type of cases
                long num = s[i] - '0';
                while(i+1 < size && isdigit(s[i+1])){
                    num = num * 10 + s[i+1] - '0';
                    i++;
                }
                
                res += num * sign;
            }
            
            // if current char is '+' then change the sign to 1, it means positive
            else if(s[i] == '+'){
                sign = 1;
            }
            
            // if current char is '-' then change the sign to 1, it means negative
            else if(s[i] == '-'){
                sign = -1;
            }
            
            // if current char is '(', then push the res & sign, and reinitialize res as 0, and sign as 1(positive)
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            
            // if current char is ')', then multiply the res with sign(immediate top of the stack), and add the res(next top of the stack), and simultaneously pop the value from stack as well
            else if(s[i] == ')'){
                int sign = st.top(); st.pop();
                int value = st.top(); st.pop();
                res = res * sign + value;
            }
        }
        
        // return the res
        return res;
    }
};
