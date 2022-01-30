
// Question) 2155. All Divisions With the Highest Score of a Binary Array


// Implementation

// Time Complexity = O(N)
// Iterating two time
// Space Complexity = O(1), not considering res vector, bcz its a part of output

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        int n = nums.size(), ans = INT_MIN;
        
        // will be having the count of 0 and 1 into respective variable
        int countZero = 0, countOne = 0;
        
        // couting the number of one present into the nums
        for(int itr = 0; itr < n; itr++){
            if(nums[itr] == 1) countOne++;
        }
        
        // reserving the count of one, bcz we will need it for 2nd loop
        int reserveCountOne = countOne;
               
        // iterating over the nums
        for(int itr = 0; itr <= n; itr++){
            
            // numsleft
            int numsLeft = 0;
            if(itr != 0 && nums[itr - 1] == 0){
                countZero++;
            }
            numsLeft = countZero;
            
            // numsright
            int numsRight = 0;
            if(itr != 0 && nums[itr - 1] == 1){
                countOne--;
            }
            numsRight = countOne;

            // if (numsLeft + numsRight) is not equal to 0 and it's more than equal to ans, then update the ans
            if(((numsLeft + numsRight) != 0) && (ans <= (numsLeft + numsRight))){
                ans = numsLeft + numsRight;
            }
        }
        
        // intializing the value again for 2nd looping
        countZero = 0, countOne = reserveCountOne;
        
        // to store the result
        vector<int> res;
        
        // iterating over the nums
        for(int itr = 0; itr <= n; itr++){
            
            // numsleft
            int numsLeft = 0;
            if(itr != 0 && nums[itr - 1] == 0){
                countZero++;
            }
            numsLeft = countZero;
            
            // numsright
            int numsRight = 0;
            if(itr != 0 && nums[itr - 1] == 1){
                countOne--;
            }
            numsRight = countOne;            
            
            // if (numsLeft + numsRight) is not equal to 0 and it's more than equal to ans, then push the index into res vector
            if(((numsLeft + numsRight) != 0) && (ans == (numsLeft + numsRight))){                
                res.push_back(itr);
            }
        }
        
        return res;
    }
};
