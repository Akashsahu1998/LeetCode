
// Question) 9. Palindrome Number


// Implementation

// 1st Approach
// Idea: Convert into string, then just use two pointer's technique
// Time Complexity: O(N/2) => O(N)
// Space Complexity: O(1), if we are not considering string into space
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



// 2nd Approach
// Idea: reverse the half number
// Time Complexity: O(LogN)
// Space Complexity: O(1)
class Solution {
public:    
    bool isPalindrome(int x) {
        
        // (x < 0) -> bcz, anyone value which is less than 0, its means false
        // (x != 0) -> bcz, for this case x = 0, in this case, it should return true, bcz that is pallindrome
        // (x%10 == 0) -> bcz, for these cases, x = 10, x = 20
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        // will store the reverse of the number
        int rev = 0;
        
        // running till the half of the number, so in this way, we can handle the overflow case also
        while(x > rev){
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        
        // if x == rev, means both half are equal, i.e, x = 1331
        // (rev/10 == x), means if the num is odd, i.e, x = 13331
        return (x == rev) || (rev/10 == x);
    }
};
