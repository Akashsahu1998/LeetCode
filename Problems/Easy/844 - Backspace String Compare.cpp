
// Question) 844. Backspace String Compare


// Implementation

// 1st Approach
// Naive Approach
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


// 2nd Approach
// Efficient Approach
// Time Complexity: O(M + N)
// Space Complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        
        while(true){
            int backSpaceCount = 0;
            while(i >= 0 && (backSpaceCount > 0 || s[i] == '#')){
                backSpaceCount += s[i] == '#' ? 1 : -1;
                i--;
            }
            
            backSpaceCount = 0;
            while(j >= 0 && (backSpaceCount > 0 || t[j] == '#')){
                backSpaceCount += t[j] == '#' ? 1 : -1;
                j--;
            }
            
            if(i >= 0 && j >= 0 && s[i] == t[j]){
                i--;
                j--;
            }
            else break;
        }
        
        return i==-1 && j==-1;
    }
};
