
// Question) 67. Add Binary


// Implementation

// Time Complexity = O(max(m, n)), Space Complexity = O(max(m, n)), where m & n is the length of a & b;
class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        
        int carry = 0;
        int itr = a.size()-1;
        int jtr = b.size()-1;
        while(itr >= 0 || jtr >= 0){
            int midSum = carry;
            if(itr >= 0){
                midSum += a[itr] - '0';
            }
            
            if(jtr >= 0){
                midSum += b[jtr] - '0';
            }
            
            carry = midSum > 1 ? 1 : 0;
            sum += to_string(midSum % 2);
            
            itr--; jtr--;
        }
        
        if(carry) sum += to_string(carry);
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
