
// Question) 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit


// Implementation

// Using Dequeue & 2 Pointers
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        // maxElements will hold the elements in decreasing order, and
        // minElements will hold the elements in increasing order
        deque<int> maxElements, minElements;
        
        // taking two pointers
        // j will always move forward always, and
        // i will only move forward, when max & min element will cross the limit
        int i = 0, j;
        for(j = 0 ; j < nums.size(); j++){
            
            // if maxElements is not empty & if its back is having smaller element than jth current element in nums, then pop it, bcz maxElements is maintaining a decreasing order
            while(!maxElements.empty() && maxElements.back() < nums[j]){
                maxElements.pop_back();
            }
            
            // if minElements is not empty & if its back is having greater element than jth current element in nums, then pop it, bcz itminElements is maintaining a increasing order
            while(!minElements.empty() && minElements.back() > nums[j]){
                minElements.pop_back();
            }
            
            // push the current jth value of nums, into maxElements & minElements
            maxElements.push_back(nums[j]);
            minElements.push_back(nums[j]);
            
            // if the max & min element will cross the limit, then i will move forward,
            if(maxElements.front() - minElements.front() > limit){
                
                // if maxElements front is having same value as nums[i], it means needs to pop it, its a old value, and its out of the subarray
                if(maxElements.front() == nums[i]) maxElements.pop_front();
                
                // if minElements front is having same value as nums[i], it means needs to pop it, its a old value, and its out of the subarray
                if(minElements.front() == nums[i]) minElements.pop_front();
                i++;
            }
        }        
        
        // return result
        return j-i;
    }
};
