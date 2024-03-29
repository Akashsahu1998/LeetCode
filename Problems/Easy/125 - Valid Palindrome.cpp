
// Question) 125. Valid Palindrome

// LC Solution : https://leetcode.com/problems/valid-palindrome/discuss/2738575/2-approaches-naive-to-efficient-2-pointers-c 

// Implementation

// 1st Approach
// Naive Approach, 2 iteration
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        string myStr;
        transform(s.begin(), s.end(), s.begin(), :: tolower); 
        for(int i = 0; i < s.length(); i++){
            if( (s[i] >= 97 && s[i] <= 122) || ((s[i] >= 48 && s[i] <= 57)) ){
                myStr += s[i];   
            }
        }      
        int start = 0, end = myStr.length() - 1;
        while(start < end){
            if(myStr[start] != myStr[end]){
                ans = false; break;
            }
            ans = true;
            start++; end--;
        }
        return ans;
    }
};


// 2nd Approach
// Efficient Approach
// Using 2 Pointers, only 1 iteration
// Time Complexity : O(N/2) => O(N)
// Space Complexity : O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0, right = s.size()-1;
        while(left < right){
            
            // if char is alphabet, return false if they are not equal
            if(isalpha(s[left]) && isalpha(s[right])){
                if(tolower(s[left]) != tolower(s[right])) return false;
            }
            
            // if char is digit, return false if they are not equal
            else if(isdigit(s[left]) && isdigit(s[right])){
                if(s[left] != s[right]) return false;
            }
            
            // if char is alphabet or digit, it means they are equal, return false
            else if((isalpha(s[left]) || isalpha(s[right])) && (isdigit(s[left]) || isdigit(s[right]))){
                return false;
            }
            
            // if char is not alphanumeric then increase/decrease left/right variables
            else {
                if(isalpha(s[left]) || isdigit(s[left])){
                    right--;
                }
                else{
                    left++;
                }
                continue;
            }
            left++;
            right--;
        }
        return true;
    }
};
