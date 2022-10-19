
// Question) 66. Plus One


// Implementation

// 1st Approach
// Naive Approach
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size());
        int carry = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            int val = digits[i] + carry;
            if(i == digits.size()-1){
                val += 1;
            }
            carry = val==10 ? 1 : 0;
            res[i] = val==10 ? 0 : val + carry;
        }
        
        if(carry){
            vector<int> newRes(digits.size()+1);
            newRes[0] = carry;
            for(int i = 0; i < res.size(); i++){
                newRes[i+1] = res[i];
            }
            res = newRes;
        }
        return res;
    }
};


// 2nd Approach
// Efficient Approach
// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        
        // If all values in array are 9
        vector<int> res(digits.size()+1);
        res[0] = 1;
        return res;
    }
};
