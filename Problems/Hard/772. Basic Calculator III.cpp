
// Question) 772. Basic Calculator III


// Implementation

// Using Stack & Recursion
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
private:
    // finding the current number 
    int parseNumber(string s, int &i){
        int num = 0;
        while(i < s.size() && isdigit(s[i])){
            num = num * 10 + s[i] - '0';
            i++;
        }
        return num;
    }
    
    // parsing the expression
    int parseExpression(string s, int &i){
        char curOperator = '+';
        stack<int> st;
        
        for( ; i < s.size() && curOperator != ')'; i++){
            // if currentChar is having space then no sense of moving forward
            if(s[i] == ' ') continue;
            
            int num = 0;
            
            // parsing bracket by bracket
            if(s[i] == '('){
                num = parseExpression(s, ++i);
            }
            else {
                num = parseNumber(s, i);
            }
            
            // if curOperator is having any valid operator then only performing operation
            // if not valid then no case will execute, and will not perform any operation
            switch(curOperator){
                case '+':
                    st.push(num);
                    break;
                    
                case '-':
                    st.push(-num);
                    break;
                    
                case '*':
                    st.top() *= num;
                    break;
                    
                case '/':
                    st.top() /= num;
                    break;
            }
            
            curOperator = s[i];            
        }
        
        // generating the sum of all elements of stack and returning it
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
    
public:
    int calculate(string s) {
        int i = 0;
        return parseExpression(s, i);
    }
};
