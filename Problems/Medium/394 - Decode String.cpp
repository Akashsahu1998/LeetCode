
// Question) 394. Decode String


// Implementation

// 1st
// Naive Approach
// Using 2 stacks
// Time Complexity = O(N), Space Complexity = O(N)
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
