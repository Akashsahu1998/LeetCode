
// Question) 540. Single Element in a Sorted Array


// Implementation

// Using Binary Search
// 1st Approach
// Time Complexity = O(LogN)
// Space Complexity = O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-2; 
       
        while(left <= right){
            int mid = left + (right-left)/2;
           
            if(mid%2 == 0 && nums[mid+1] == nums[mid] || 
               mid%2 == 1 && nums[mid-1] == nums[mid]) {
                left = mid+1;
            }
            else right = mid-1;
        }
        return nums[left];
    }
};


// Using Binary Search
// 2nd Approach
// Time Complexity = O(LogN)
// Space Complexity = O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        else if(nums[0] != nums[1]) return nums[0];
        else if(nums[n-1] != nums[n-2]) return nums[n-1];
        
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            
            if(mid%2 == 0 && nums[mid+1] == nums[mid] || 
               mid%2 == 1 && nums[mid-1] == nums[mid]) {
                start = mid+1;
            }
            else end = mid-1;
        }
        return -1;
    }
};
