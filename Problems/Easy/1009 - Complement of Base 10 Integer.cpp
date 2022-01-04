
// Question) 1009. Complement of Base 10 Integer


// Implementation

// Time Complexity = O(logN), Space Complexity = O(1) not considering string length
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string str = "";
        while(n){
            str += (n % 2) ? '0' : '1';
            n /= 2;
        }
        
        int dig = 1, res = 0;
        for(int itr = 0; itr < str.size(); itr++){
            if(str[itr] == '1') res += dig;
            dig *= 2;
        }
        
        return res;
    }
};
