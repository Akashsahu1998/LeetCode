class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str(n);
        for(int itr = 1; itr <= n; itr++){
            if(itr % 3 == 0) str[itr - 1] += "Fizz";
            if(itr % 5 == 0) str[itr - 1] += "Buzz";
            if(str[itr - 1].empty()) str[itr - 1] += to_string(itr);
        }
        return str;
    }
};
