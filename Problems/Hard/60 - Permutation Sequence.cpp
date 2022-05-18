
// Question) 60. Permutation Sequence


// Implementation

// Using Maths
// Time Complexity : O(N^2)
// Space Complexity : O(N)

class Solution {
public:
    string getPermutation(int n, int k) {
        
        int factorial = 1;
        vector<int> nums;
        
        for(int i = 1; i < n; i++){
            factorial *= i;
            nums.push_back(i);
        }        
        nums.push_back(n);        
        k--;
        
        string res;
        do{
            res += to_string(nums[k / factorial]);
            nums.erase(nums.begin() + (k / factorial));
            
            if(nums.size() == 0) break;
            
            k %= factorial;
            factorial /= nums.size();
        }while(true);
        
        return res;
    }
};
