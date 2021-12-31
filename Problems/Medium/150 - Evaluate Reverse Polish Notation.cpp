
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
                if(a == "+") st.push(num1 + num2);
                else if(a == "-") st.push(num1 - num2);
                else if(a == "*") st.push(num1 * num2);
                else st.push(num1 / num2);             
            }
        }
        return st.top();
    }
};

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // will be using the tokens vector as a stack
        
        int top = 0;
        for(auto a : tokens){
            if(a != "+" && a != "-" && a != "*" && a != "/"){
                tokens[top++] = a;
            }
            else{
                int num1 = stoi(tokens[--top]);
                int num2 = stoi(tokens[--top]);
                
                if(a == "+") num2 += num1;
                else if(a == "-") num2 -= num1;
                else if(a == "*") num2 *= num1;
                else num2 /= num1;
                
                tokens[top++] = to_string(num2);
            }
        }
        return stoi(tokens[0]);
    }
};
