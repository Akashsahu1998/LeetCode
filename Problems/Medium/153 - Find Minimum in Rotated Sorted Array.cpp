
// Question) 153. Find Minimum in Rotated Sorted Array


// Implementation

// Using Binary Search
// Time Complexity: O(LogN)
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, minVal = INT_MAX;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(nums[left] <= nums[mid]){
                minVal = min(minVal, nums[left]);
                left = mid+1;
            }
            else{
                minVal = min(minVal, nums[mid]);
                right = mid-1;
            }
        }
        
        return minVal;
    }
};
