
// Question) 81. Search in Rotated Sorted Array II


// Implementation

// Using Binary Search
// Time Complexity => Average Case : O(LogN), Worst Case : O(N)
// Space Complexity => O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
               
            if(nums[mid] == target) return true;
            
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }            
            else if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target <= nums[mid]) right = mid-1;
                else left = mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};
