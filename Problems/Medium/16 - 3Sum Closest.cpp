
// Question) 16. 3Sum Closest


// Implementation

// Best Solution
// Using Sorting and 3 Pointers
// Time Complexity = O(NlogN * NlogN) = O(N^2 log N)
// Space Complexity = O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         // sort the array
        sort(nums.begin(), nums.end());
        
        // using closestSum as a result
        int n = nums.size(), closestSum = nums[0] + nums[1] + nums[n-1];
        
        // use itr as a first pointer
        // running till n-2 bcz, we can use 3 pointers(values) only to find the closest sum
        for(int itr = 0; itr < n-2; itr++){
            int low = itr+1, high = n-1;
            
            // use low & high as a 2nd and 3rd pointer
            while(low < high){
                
                // find the currentSum of all pointer's index value from nums
                int currentSum = nums[itr] + nums[low] + nums[high];    
                
                // if currentSum is greater than target then decrement high by 1, otherwise increment low by 1
                (currentSum > target) ? high-- : low++;
                
                // if the currentSum difference is less than the closestSum difference then update the closestSum
                if(abs(currentSum - target) < abs(closestSum - target)){
                    closestSum = currentSum;
                }
            }
        }
        
        return closestSum;
    }
};
