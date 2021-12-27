
// Question) 678. Valid Parenthesis String


// Implementation

// Vide link : https://www.youtube.com/watch?v=KuE_Cn3xhxI
// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    bool checkValidString(string str) {
        stack<char> star, open;
        
        for(int itr = 0; itr < str.size(); itr++){
            if(str[itr] == '(') open.push(itr);
            else if(str[itr] == '*') star.push(itr);
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        
        while(!open.empty()){
            if(star.empty()) return false;
            else if(open.top() < star.top()){
                open.pop();
                star.pop();
            }
            else return false;
        }        
        
        return true;
    }
};
