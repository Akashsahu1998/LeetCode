
// Question) 7. Reverse Integer


// Implementation

// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x){            
            // before updating res, just check whether its greater than (INT_MAX/10) or less than (INT_MIN/10), if it is, then return 0
            if (res > INT_MAX/10 || res < INT_MIN/10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
