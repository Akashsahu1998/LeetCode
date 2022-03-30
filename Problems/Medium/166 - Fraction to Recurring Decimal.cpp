
// Question) 166. Fraction to Recurring Decimal


// Implementation

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(!numerator) return "0";
        
        string ans;
        
        // it means, if both are neg then it will become pos, but if any one is neg then it will become neg, if both are pos, then obvisouly it will be pos only, pos means no need to add that neg symbol
        if((numerator > 0) ^ (denominator > 0)){
            ans += "-";
        }
        
        long num = labs(numerator), den = labs(denominator);
        
        long quotient = num / den;
        long remainder = num % den;
        if(!remainder){
            ans += to_string(quotient);
            return ans;
        }
        ans += to_string(quotient) + '.';
        unordered_map<long, int> freq;
        
        while(remainder){
            if(freq.find(remainder) != freq.end()){
                ans.insert(freq[remainder], "(");
                ans += ')';
                break;
            }
            else{
                freq[remainder] = ans.size();
                remainder *= 10;
                quotient = remainder / den;
                remainder = remainder % den;
                ans += to_string(quotient);
            }
        }
        
        return ans;
    }
};
