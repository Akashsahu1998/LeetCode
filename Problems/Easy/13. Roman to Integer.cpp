
// Question) 13. Roman to Integer

// LC Solution : https://leetcode.com/problems/roman-to-integer/discuss/2743700/Straight-forward-solution-C%2B%2B

// Implementation


// Left-to-Right Pass Aproach
// Time Complexity: O(1), bcz the given input roman number will be in the range of (1 - 3999)
// Space Complexity: O(1)

class Solution {
private:
    int getValue(char symbol){
        if(symbol == 'I') return 1;
        else if(symbol == 'V') return 5;
        else if(symbol == 'X') return 10;
        else if(symbol == 'L') return 50;
        else if(symbol == 'C') return 100;
        else if(symbol == 'D') return 500;
        else return 1000; // for M
    }
public:
    int romanToInt(string s) {
        int sum = 0, i = 0;
        while(i < s.size()){
            char currentSymbol = s[i];
            int currentValue = getValue(currentSymbol);
            
            // check next value
            // if next value is big then subtract current from next value.
            int nextValue = 0;
            if(i+1 < s.size()){
                char nextSymbol = s[i+1];
                nextValue = getValue(nextSymbol);
            }
            
            // For this case => Ex = CM 
            // M - C = 1000 - 100 => 900
            // increasing i by 2, bcz we are using 2 indexes here
            if(currentValue < nextValue){
                sum += (nextValue - currentValue);
                i += 2;
            }
            else{
                sum += currentValue;
                i += 1;
            }
        }
        
        return sum;
    }
};
