
// Question) 415. Add Strings


// Implementation

// LC Solution : https://leetcode.com/problems/add-strings/discuss/2733171/Normal-Math-Easy-to-Understand-Straightforward-Solution-C%2B%2B

// Using Normal Maths
// Time Complexity = O(Max(N1, N2)), where N1 = num1.size(), N2 = num2.size()
// Space Complexity = O(1), not assuming ans string, bcz thats a part of output

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string ans = "";        
        int carry = 0, i = num1.size()-1, j = num2.size()-1;
        
        while(i >= 0 || j >= 0){
            int val1 = (i >= 0) ? (num1[i] - 48) : 0;
            int val2 = (j >= 0) ? (num2[j] - 48): 0;
            
            int sum = val1 + val2 + carry;
            carry = (sum > 9) ? 1 : 0;
            ans = (sum > 9) ? (to_string(sum%10) + ans) : (to_string(sum) + ans);
            
            i--;
            j--;
        }
        
        if(carry){
            ans = to_string(carry) + ans;
        }
        
        return ans;
    }
};
