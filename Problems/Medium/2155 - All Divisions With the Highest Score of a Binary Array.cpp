
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


// 2nd Approach
// Time Complexity = O(N)
// Space Complexity = O(1), not considering res vector, bcz its a part of output

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        int n = nums.size(), maxAns = INT_MIN, countLeftZero = 0;
        
        // getting the count of 1 in the array
        int countRightOne = accumulate(nums.begin(), nums.end(), 0);
        
        // to store the result
        vector<int> res;
        
        // iterating over the nums
        for(int itr = 0; itr <= n; itr++){
            
            // if count of the 0 on left side + count of the 1 on right side is more than maxAns, then clear the res vector and push the current index into it.
            if((countLeftZero + countRightOne) > maxAns){
                maxAns = countLeftZero + countRightOne;
                res.clear();
                res.push_back(itr);
            }   
            
            // if count of the 0 on left side + count of the 1 on right side is equal to maxAns, then push the current index into it.
            else if((countRightOne + countLeftZero) == maxAns) res.push_back(itr);
                        
            if(itr != n){
                
                // if current value is 0 then increase the count of 0 on the left side
                if(nums[itr] == 0) countLeftZero++;
                
                // if current value is 1 then decrease the count of 1 on the right side
                if(nums[itr] == 1) countRightOne--;
            }
        }
        return res;
    }
};
