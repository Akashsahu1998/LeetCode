
// Question) 70. Climbing Stairs


// Implementation

// Using Fibonacci Approach
// Time Complexity : O(N)
// Time Complexity : O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int prev2 = 1, prev1 = 2;
        for(int i = 3; i <= n; i++){
            int temp = prev1 + prev2;
            prev2 = prev1;
            prev1 = temp;
        }
        
        return prev1;
    }
};
