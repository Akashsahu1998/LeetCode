
// Question) 154. Find Minimum in Rotated Sorted Array II


// Implementation

// Using Binary Search
// Time Complexity: O(LogN)
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while(left < right){
            int mid = left + (right - left)/2;
            
            if(nums[mid] < nums[right]) right = mid;
            else if(nums[mid] == nums[right]) right--;
            else left = mid+1;
        }
        
        return nums[left];
    }
};	
