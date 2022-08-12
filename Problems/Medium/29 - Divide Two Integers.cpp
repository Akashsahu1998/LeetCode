
// Question) 29. Divide Two Integers


// Implementation

// Using Repeated exponential searches approach
// Time Complexity = O(logN * logN), we can store the internal while loop generated number and power of two into an array as well, but it was will cause us O(logN) space complexity as well.
// Space Complexity = O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // special case
        // bcz, if dividend is INT_MIN = -2147483648, and divisor is -1, and if we are converting into positive (2147483648), it will overflow the int value, so in this case we need to return the INT_MAX value which is 2147483647
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        int HALF_INT_MIN = -1073741824;
        int countNegativeNumber = 2;
        
        // converting into negative to avoid int overflow
        if(dividend > 0){
            countNegativeNumber--;
            dividend = -dividend;
        }
        
        if(divisor > 0){
            countNegativeNumber--;
            divisor = -divisor;
        }
        
        int quotientResult = 0;
        while(dividend <= divisor){
            
            int value = divisor;
            int powerOfTwo = -1;
            
            // check HALF_INT_MIN as well bcz of the int overflow issue
            while(value >= HALF_INT_MIN && value+value >= dividend){
                value += value;
                powerOfTwo += powerOfTwo;
            }
            
            dividend -= value;
            quotientResult += powerOfTwo;
        }
        
        if(countNegativeNumber != 1){
            return -quotientResult;
        }
        
        return quotientResult;
    }
};


// special test cases
// dividend = -2147483648
// divisor = 1
// dividend = -2147483647
// divisor = -1
