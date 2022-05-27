
// Question) 844. Backspace String Compare


// Implementation

// Naive Approach
// 1st Approach
// Time Complexity: O(M + N)
// Space Complexity: O(M + N)
    
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0, j = 0;
        string str1, str2;
        
        while(i < s.size() || j < t.size()){
            
            if(i < s.size()){                
                if(s[i] == '#'){
                    if(str1.size()) str1.pop_back();
                }else{
                    str1 += s[i];
                }   
                i++;
            }
            
            if(j < t.size()){
                if(t[j] == '#'){
                    if(str2.size()) str2.pop_back();
                }else{
                    str2 += t[j];
                }   
                j++;
            }
        }
        
        return str1 == str2;
    }
};
