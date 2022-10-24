
// Question) 163. Missing Ranges

// LC Solution : https://leetcode.com/problems/missing-ranges/discuss/2738972/Linear-Iteration-Comments-included-C%2B%2B

// Implementation

// Linear Iteration
// Time Complexity = O(N)
// Space Complexity = O(1), not considering the res vector, bcz its a part of output

class Solution {
private:
    // to generate range
    string formatMissingRange(int lower, int upper){
        
        // if both are equal, so there is no range, only single number
        if(lower == upper){
            return to_string(lower);
        }
        
        // generate the range
        return to_string(lower) + "->" + to_string(upper);
    }
    
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        // will store result
        vector<string> res;
        
        // (lower-1) bcz moving forward we will be using prev+1 everywhere
        int prev = lower-1;
        
        for(int i = 0; i <= nums.size(); i++){
            
            // cur is nothing but, it will hold the value of nums ith element
            int cur = (i<nums.size()) ? nums[i] : upper+1;
            
            if(prev+1 < cur){
                
                // generate the range from prev+1 to cur-1
                res.push_back(formatMissingRange(prev+1, cur-1));
            }
            
            prev = cur;
        }
        
        // return result
        return res;
    }
};
