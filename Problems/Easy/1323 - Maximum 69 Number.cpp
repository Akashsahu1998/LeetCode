
// Question) 1323. Maximum 69 Number

// Implementation

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> vect;
        int rem, n = num;
        while(n > 0){		// Converting number to vector
            rem = n % 10;
            vect.emplace_back(rem);
            n /= 10;
        }
        		
        reverse(vect.begin(), vect.end());		// Reversing the vector
        for(int itr = 0; itr < vect.size(); itr++){
            if(vect[itr] == 6){			// If element is 6 then replace it by 9 only once
                vect[itr] = 9;
                break;
            }  
        }
        
        int result = 0;
        for(int itr = 0; itr < vect.size(); itr++){			// Converting vector to number
            result = result * 10 + vect[itr];
        }
        return result;		// returning the result
    }
};
