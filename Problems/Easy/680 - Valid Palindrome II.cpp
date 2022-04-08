
// Question) 680. Valid Palindrome II


// Implementation

// Using Two Pointer Approach
// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
private:
    bool checkPalindrome(string s, int& i, int& j) {
        while(i < j){
            if(s[i] != s[j]) return false;       
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        
        if(checkPalindrome(s, i, j)) return true;
        
        // taking left & right bcz, we are passing by reference, so bcz of this another argument may can get wrong starting values in the below if condition
        int left = i, right = j;
        
        if(checkPalindrome(s, ++left, right) || checkPalindrome(s, i, --j)) return true;
        
        return false;
    }
};
