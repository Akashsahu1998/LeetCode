
// Question) 34. Find First and Last Position of Element in Sorted Array


// Implementation

// 1st Approach
// Brute Force
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;        
        int pos = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                pos = mid;
                break;
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        if(pos == -1) return {-1, -1};
        
        int first = pos, last = pos;
        
        while(first > 0 && nums[first] == nums[first-1]) first--;
        
        while(last < nums.size()-1 && nums[last] == nums[last+1]) last++;
        
        return {first, last};
    }
};


// 2nd Approach
// Efficient Approach
// Using Binary Search
// Time Complexity = O(LogN)
// Space Complexity = O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1,-1};
        
        int low = 0, high = nums.size()-1;        
        int firstPos = -1, lastPos = -1;
        
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] < target) low = mid+1;
            else high = mid;
        }        
        if(nums[low] != target) return {-1,-1};
        firstPos = low;
        
        // only change high, don't change low
        high = nums.size()-1;
        while(low < high){
            int mid = (low + (high-low)/2) + 1;
            
            if(nums[mid] > target) high = mid-1;
            else low = mid;
        }
        lastPos = high;
        return {firstPos, lastPos};
    }
};

// Algo Steps
// 1) Use Binary Search
// 2) Firstly try to find the left side with the help of first binary search
// 3) After finding the left side, try to find the right side, between that leftSide and high with the help of first binary search.
