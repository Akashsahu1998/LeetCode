
// Question) 8. String to Integer (atoi)


// Implementation


// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int myAtoi(string s) {
        int itr = 0, n = s.size();
        
        // skip all leading spaces
        while(s[itr] == ' ') itr++;
        
        // check whether its negative or position number
        int sign = 1;
        if(itr < n && s[itr] == '+' || s[itr] == '-'){
            sign = (s[itr++] == '+') ? 1 : -1;            
        }
        
        // read the next char's until and unless the non digit char occurs or end of the string reached
        // if non digit char occurs just ignore the rest of the string
        int num = 0;
        while(itr < n && s[itr] >= '0' && s[itr] <= '9'){
            
            // if(num > INT_MAX/10) is true, then you should return INT_MAX, but 
            // if they are equal(num == INT_MAX/10), then check the unit place(s[itr] - '0' > 7), now why 7? bcz
            // INT_MAX means this value (2147483647), its having 7 on its unit place, so suppose (2147483647/10) is equal to x(any number) value, then we need to check the unit place, right, if its more than 7, it means that is big and our condition will become true, otherwise if its small then condition will become false
            if(num > INT_MAX/10 || (num == INT_MAX/10 && s[itr] - '0' > 7)){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            // creating the number
            num = num * 10 + (s[itr++] - '0');
        }
        
        // if sign is -1 then negative number will return, if its 1 then positive number will return
        return sign * num;
    }
};
