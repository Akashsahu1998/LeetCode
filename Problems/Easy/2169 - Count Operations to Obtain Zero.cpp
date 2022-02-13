
// Question) 2169. Count Operations to Obtain Zero

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        
        // run the loop, untill & unless any one of the number num1 or num2 become 0
        while(num1 != 0 && num2 != 0){        
            // if num1 is greater than num2, then subtract num2 from num1, otherwise subtract num1 from num2
            if(num1 > num2) num1 -= num2;
            else num2 -= num1;
            
            // count the number of operations
            count++;
        }        
        return count;
    }
};
