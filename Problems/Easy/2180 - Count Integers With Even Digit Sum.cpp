
// Question) 2180. Count Integers With Even Digit Sum


// Implementation

// Brute Force Approach
// Time Complexity: O(NLogN)
// Space Complexity: O(1)
// Idea: traversing from 1 to num, and generating the sum of the digits of each number, and checking whether they are even or odd, and counting

class Solution {
public:
    
    // generating the sum of the digits of the number, if the sum is even return true, otherwise return false
    bool numIsEven(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        if(sum%2) return false;
        return true;   
    }
    
    int countEven(int num) {
        int cnt = 0;        
        // traversing from 1 to num, and generating the sum of the digits of each number, and checking whether they are even or odd
        for(int itr = 1; itr <= num; itr++){
            if(numIsEven(itr)) cnt++;
        }
        return cnt;
    }
};
