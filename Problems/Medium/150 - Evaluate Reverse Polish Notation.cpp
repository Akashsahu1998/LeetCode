
// Question) 150. Evaluate Reverse Polish Notation


// Implementation

// Naive Approach
// Using stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto a : tokens){
            if(a != "+" && a != "-" && a != "*" && a != "/"){
                st.push(stoi(a));
            }
            else{
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if(a == "+"){
                    st.push(num1 + num2);
                }
                else if(a == "-"){
                    st.push(num1 - num2);
                }
                else if(a == "*"){
                    st.push(num1 * num2);
                }
                else{
                    st.push(num1 / num2);
                }                
            }
        }
        return st.top();
    }
};
