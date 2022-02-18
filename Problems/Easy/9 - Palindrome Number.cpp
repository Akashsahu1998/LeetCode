
// Question) 9. Palindrome Number


// Implementation

// 1st Approach
// Idea: Convert into string, then just use two pointer's technique
// Time Complexity: O(LogN)
// Space Complexity: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        
        // convert into string
        string str = to_string(x);
        
        // take 2 pointers, left will start from 0, and right will start from end-1
        int left = 0, right = str.size()-1;
        
        // run the loop, untill & unless left become greater than equal to right
        while(left < right){
            
            // if left and right value are not equal it means return false
            if(str[left++] != str[right--]) return false;
        }
        
        // if everything runs fine, it means, its pallindrome, then return true
        return true;
    }
};
