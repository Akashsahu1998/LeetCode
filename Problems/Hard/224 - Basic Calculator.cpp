
// Question) 224. Basic Calculator


// Implementation

// Using Stack
// Time Complexity = O(N)
// Space Complexity = O(N)
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, sign = 1, size = s.size();
        
        for(int i = 0; i < size; i++){
            
            if(isdigit(s[i])){
                long num = s[i] - '0';
                while(i+1 < size && isdigit(s[i+1])){
                    num = num * 10 + s[i+1] - '0';
                    i++;
                }
                
                res += num * sign;
            }            
            else if(s[i] == '+'){
                sign = 1;
            }
            else if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                int sign = st.top(); st.pop();
                int value = st.top(); st.pop();
                res = res * sign + value;
            }
        }
        
        return res;
    }
};
