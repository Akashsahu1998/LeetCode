
// Question) 43. Multiply Strings


// Implementation

// Using Maths
// Time Complexity: O(MN)
// Space Complexity: O(M+N)

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string str(num1.size() + num2.size(), '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int place2 = 0; place2 < num2.size(); place2++){
            
            int digit2 = num2[place2] - '0';
            
            for(int place1 = 0; place1 < num1.size(); place1++){
                int digit1 = num1[place1] - '0';
                
                int index = place1 + place2;
                
                int carry = str[index] - '0';
                int mul = digit1 * digit2 + carry;
                
                str[index] = mul%10 + '0';
                str[index+1] += mul/10;
            }
        }
        
        if(str[str.size()-1] == '0') str.pop_back();
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};
