
// Question) 191. Number of 1 Bits


// Using Bit Manipulation
// Time Complexity = O(1), it depends on the number of 11-bits in nn. In the worst case, all bits in nn are 11-bits. In case of a 32-bit integer, the run time is O(1)O(1).
// Space Complexity = O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt = 0;
        
        while(n){
            // here n means any number like 4 (100)
            // (n-1) means (4-1) = 3(011)
            // & means (4 & 3) = (100 & 011) => (000)
            // we will run the loop till n become 0
            n = (n & n-1);
            
            // will be counting, until n became 0
            cnt++;
        }
        
        return cnt;
    }
};


// Idea:
// I think the way to think about it is that for any number, lets say 4 (0100), 1 subtracted by that number will always set all the LSB's 
//below the lowest set bit and clear the lowest set bit (ie. 3 = 0011. It may be more intuitive to count upwards to see it. Anytime you go 
//from 3 to 4 you are clearing the 2 bits and increasing a higher bit (ie. bits 0 and 1 become 0 and bit 2 becomes 1 when going from 3 to 4).
//So when you do n&(n-1) you know that the last set bit is going to get cleared because 011 & 100 is 0, so you keep clearing and increment count
//along the way until all the bits are cleared (you clear them from the lowest set bit to the highest).
