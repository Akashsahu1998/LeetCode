
// Question) 2180. Count Integers With Even Digit Sum


// Implementation

// Brute Force Approach
// Time Complexity: O(NLogN)
// Space Complexity: O(1)
// Idea: traversing from 1 to num, and generating the sum of the digits of each num, and checking whether they are even or odd, and counting

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



// Optimal Approach
// Time Complexity: O(LogN)
// Space Complexity: O(1)

// Idea: Observe this pattern 
// num = 6 = [2,4,6]
// num = 10 = [2,4,6,8]
// num = 15 = [2,4,6,8,11,13,15]
// num = 20 = [2,4,6,8,11,13,15,17,19,20]
// num = 27 = [2,4,6,8,11,13,15,17,19,20,22,24,26]

// from this pattern we can observe one thing, if we are taking the sum of the digits of the num, and if that sum is even then we can directly divide our num by 2, and return the result, but if our sum if odd then we need to do (num-1)/2 to get the desired results.

class Solution {
public:
    int countEven(int num) {
        
        // creating a backup of num to use it later
        int numBackup = num;
        
        // generating the sum of the digits of the num
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        
        // if sum is odd, return (numBackup-1)/2 as per the pattern we found
        if(sum%2) return (numBackup-1)/2;
        
        // if sum is even, return numBackup/2
        else return numBackup/2;
    }
};
