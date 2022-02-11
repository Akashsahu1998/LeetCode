
// Question) 15. 3Sum


// Implementation

// Using 1 for loop & 2 pointer's approach
// Time Complexity = O(N^2)
// Space Complexity = O(1), not assuming vector of vector for result, bcz that's a part of output and we are returning that
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // store the result
        vector<vector<int>> res;
        
        // if size of nums is less than 3, it means we can't create the triplets
        if(nums.size() < 3) return res;
        
        // sort the nums
        sort(nums.begin(), nums.end());
        
        for(int itr = 0; itr < nums.size()-2; itr++){            
            
            // skip all continous same element, doing bcz to avoid duplicate triplets
            if(itr == 0 || nums[itr-1] != nums[itr]){
                
                // two pointer's approach
                // a + b + c = 0, so we can make the equation like
                // b + c = -a;
                // low + high = -sum;
                int low = itr+1, high = nums.size()-1, sum = -nums[itr];
                
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        
                        // add triplet into the result
                        res.push_back({nums[itr], nums[low], nums[high]});
                        
                        // skip all continous same element, doing bcz to avoid duplicate triplets
                        while(low < high && nums[low] == nums[low+1]) low++;
                        
                        // skip all continous same element, doing bcz to avoid duplicate triplets
                        while(low < high && nums[high] == nums[high-1]) high--;
                                                
                        low++;
                        high--;
                    }
                    
                    // if our total is less than the sum, then we need to move right, bcz greater elements are on the right side
                    else if(nums[low] + nums[high] < sum){
                        low++;
                    }
                    
                    // if our total is greater than the sum, then we need to move left, bcz smaller elements are on the left side
                    else{
                        high--;
                    }
                }                
            }
        }
        return res;
    }
};
