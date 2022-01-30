
// Question) 2155. All Divisions With the Highest Score of a Binary Array


// Implementation

// Naive Approach
// Give TLE
// Time Complexity = O(N * K * LogN)
// Space Complexity = O(1), not considering res vector, bcz its a part of output

class Solution {
public:
    
    // find the power of numbers in efficient way
    // using this way bcz of overflow issue
    // in this approach, everytime we are doing modulo, so it will never overflow
    // in pow directly we can't do modulo
    unsigned long long int findPower(int power, int jtr, int modulo){
        if(jtr == 0) return 1;
        if(jtr == 1) return power%modulo;
        
        unsigned long long int ans = 1;
        unsigned long long int temp = findPower(power, jtr/2, modulo) % modulo;
        
        // if jtr is odd
        if(jtr % 2){
            ans = (ans * power) % modulo;            
        }
        
        return (ans * (temp * temp) % modulo) % modulo;
    }
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {        
        for(int itr = 0; itr <= s.size()-k; itr++){
            
            string str = s.substr(itr, k);
            unsigned long long int ans = 0;
            
            for(int jtr = 0; jtr < str.size(); jtr++){
                unsigned long long int val = str[jtr] - int('a') + 1;                
                // unsigned long long int powVal = pow(power, jtr);
                unsigned long long int powVal = findPower(power, jtr, modulo);
                ans =  ans + (val * powVal);
                ans = ans % modulo;
            }
            
            if(ans == hashValue){
                return str;
            }
        }
        return "";
    }
};
