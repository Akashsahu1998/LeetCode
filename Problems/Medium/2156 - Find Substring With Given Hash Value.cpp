
// Question) 2155. All Divisions With the Highest Score of a Binary Array


// Implementation

// Naive Approach
// Give TLE
// Time Complexity = O(N * K * LogN)
// Space Complexity = O(1)

class Solution {
public:
    
    // find the power of numbers in efficient way
    // using this way bcz of overflow issue
    // in this approach, everytime we are doing modulo, so it will never overflow
    // in pow directly we can't do modulo
	// it will give the result into O(logN)
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



// https://www.youtube.com/watch?v=P7dX86HdNqc
// Efficient Approach
// Using sliding window technique and finding the power of numbers efficiently
// Time Complexity = O(N * LogN)
// Space Complexity = O(1)
class Solution {
public:
    
    // find the power of numbers in efficient way
    // using this way bcz of overflow issue
    // in this approach, everytime we are doing modulo, so it will never overflow
    // in pow directly we can't do modulo
    // it will give the result into O(logN)
    long long findPower(int power, int jtr, int modulo){
        if(jtr == 0) return 1;
        if(jtr == 1) return (power%modulo);
        
        long long ans = 1;
        long long temp = findPower(power, jtr/2, modulo) % modulo;
        
        // if jtr is odd
        if(jtr % 2){
            ans = (ans * power) % modulo;            
        }
        
        return (ans * ((temp * temp) % modulo)) % modulo;
    }
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {        
        reverse(s.begin(), s.end());
        long long ans = 0;
        string result;
        
        // traversing over the string
        for(int itr = 0; itr < s.size(); itr++){
            
            // we will run this, until & unless we reach to k window
            if(itr < k){                
                long long val = s[itr] - 'a' + 1;
                long long powVal = (findPower(power, k-1-itr, modulo)) % modulo;
                ans = (ans + ((val * powVal) % modulo)) % modulo;
                continue;
            }
            
            // if we got the ans 
            if(ans == hashValue){
                string ansStr = s.substr(itr-k, k);
                result = ansStr;
            }
            
            // not got the result yet, so remove the char from the window
            long long val = s[itr-k] - 'a' + 1;
            long long powVal = (findPower(power, k-1, modulo)) % modulo;
            ans = (ans + modulo - ((val * powVal) % modulo)) % modulo;
            
            // add the new char into the window now, that's why directly multiplying ans by power
            ans = (ans * power) % modulo;
            ans = (ans + (s[itr] - 'a' + 1)) % modulo;
        }
        
        // if we got the ans in the last index 
        if(ans == hashValue){
            string ansStr = s.substr(s.size()-k, k);
            result = ansStr;
        }
        
        // reversing the result, bcz in the starting we reversed the original string(s)
        reverse(result.begin(), result.end());
        return result;
    }
};
