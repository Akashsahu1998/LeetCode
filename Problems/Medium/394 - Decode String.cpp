
// Question) 394. Decode String


// Implementation

// 1st
// Naive Approach
// Using 2 stacks
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    string decodeString(string s) {
        stack<int> intSt;   // int stack
        stack<string> strSt;    // string stack
        string res = "";
        int itr = 0;
        while(itr < s.size()){
            if(isdigit(s[itr])){
                int num = 0;
                while(isdigit(s[itr])){
                    num = num * 10 + s[itr++] - '0';
                }
                intSt.push(num);
            }
            else if(s[itr] == ']'){
                int times = intSt.top();
                intSt.pop();
                
                string str = strSt.top();
                strSt.pop();
                
                for(int itr = 1; itr <= times; itr++){
                    str += res;
                }
                
                res = str;
                itr++;
            }
            else if(s[itr] == '['){
                strSt.push(res);
                res = "";
                itr++;
            }
            else{
                res += s[itr];
                itr++;
            }
        }
        return res;
    }
};



// 2nd
// Efficient Approach
// Using 1 stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;   // char stack        
        for(int itr = 0; itr < s.size(); itr++){
            if(s[itr] == ']'){
                string str = "";
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }                
                st.pop();
                
                string times = "";
                while(!st.empty() && isdigit(st.top())){
                    times = st.top() + times;
                    st.pop();
                }
                
                int count = stoi(times);
                
                while(count--){
                    for(int jtr = 0; jtr < str.size(); jtr++){
                        st.push(str[jtr]);
                    }
                }
            }
            else{
                st.push(s[itr]);
            }
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



// 3rd
// Recursive Approach
// Time Complexity = O(N), Space Complexity = O(N), considering the resursion stack
class Solution {
public:
    string decodeTheString(string s, int &itr){
        string res = "";
        
        while(itr < s.size() && s[itr] != ']'){
            if(isdigit(s[itr])){
                int num = 0;
                while(itr < s.size() && isdigit(s[itr])){
                    num = num * 10 + (s[itr++] - '0');
                }
                // to escape the '['
                itr++;
                
                // store the return result and repeat it num times
                string temp = decodeTheString(s, itr);
                
                // to escape the ']'
                itr++;
                
                while(num--){
                    res += temp;
                }
            }
            else{
                res += s[itr++];
            }
        }
        
        return res;    
    }
    
    string decodeString(string s) {
        int itr = 0;
        return decodeTheString(s, itr);
    }
};
