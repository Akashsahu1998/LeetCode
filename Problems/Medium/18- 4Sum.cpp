
// Question) 18. 4Sum


// Implementation

// Using two for loop & 2 pointer's approach
// Time Complexity = O(N^3)
// Space Complexity = O(1), not assuming vector of vector for result, bcz that's a part of output and we are returning that
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // taking res vector to store the result
        vector<vector<int> > res;
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        for(int itr = 0; itr <= n-4; itr++){
            for(int jtr = itr+1; jtr <= n-3; jtr++){
                
                // storing two sum using itr & jtr
                long long twoSum = nums[itr] + nums[jtr];
                
                // using two pointers approach
                int left = jtr+1, right = n-1;                
                while(left < right){
                    
                    // storing four sum using twoSum, left & right
                    // taking long long for this case, i.e = nums = [1000000000,1000000000,1000000000,1000000000], target = 0
                    long long fourSum = twoSum + nums[left] + nums[right];
                    
                    // if fourSum is greater than target, then decrement right
                    if(fourSum > target){
                        right--;
                    }   // if fourSum is less than target, then increment left
                    else if(fourSum < target){
                        left++;
                    }
                    else{   // if fourSum is equal to target then store all the four elements into result
                        vector<int> quadruplets = {nums[itr], nums[jtr], nums[left], nums[right]};
                        res.push_back(quadruplets);
                        
                        // suppose there are duplicates, so we need to move ahead our left and right from there, i.e = [1,1,1,2,2,3,3,4,4,4]
                        while(left < right && quadruplets[2] == nums[left]) left++;
                        
                        while(left < right && quadruplets[3] == nums[right]) right--;
                    }
                }
                
                // here also we need to move jtr ahead, bcz duplicates can be present here, i.e = [1,1,1,2,2,3,3,4,4,4]
                while(jtr+1 < n && nums[jtr+1] == nums[jtr]) jtr++;
            }
            
            // here also we need to move itr ahead, bcz duplicates can be present here, i.e = [1,1,1,2,2,3,3,4,4,4]
                while(itr+1 < n && nums[itr+1] == nums[itr]) itr++;
        }
        return res;
    }
};
