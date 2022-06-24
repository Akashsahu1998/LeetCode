
// Question) 227. Basic Calculator II


// Implementation

// Using Stack
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0 || s == "") return 0;
        
        stack<int> st;
        int currentNumber = 0;
        char sign = '+';
        
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                currentNumber = (currentNumber*10) + (s[i] - '0');
            }
                        
            // (s[i] != ' ') bcz there can we space as well in the string
            // that's why taking (i == size()-1), bcz we need to perform operation over last char as well
            // i.e = s = 4/2
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1){
                if(sign == '+'){
                    st.push(currentNumber);
                }
                else if(sign == '-'){
                    st.push(-currentNumber);
                }
                else if(sign == '*' || sign == '/'){
                    int topValue = st.top();
                    st.pop();
                    if(sign == '*') st.push(topValue * currentNumber);
                    else st.push(topValue / currentNumber);
                }
                
                currentNumber = 0;
                sign = s[i];
            }
        }
        
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    }
};
