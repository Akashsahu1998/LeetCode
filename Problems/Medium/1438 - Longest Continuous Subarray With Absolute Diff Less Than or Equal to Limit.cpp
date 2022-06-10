
// Question) 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit


// Implementation

// Using Dequeue
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxElements, minElements;
        
        int i = 0, j;
        for(j = 0 ; j < nums.size(); j++){
            
            while(!maxElements.empty() && maxElements.back() < nums[j]){
                maxElements.pop_back();
            }
            
            while(!minElements.empty() && minElements.back() > nums[j]){
                minElements.pop_back();
            }
            
            maxElements.push_back(nums[j]);
            minElements.push_back(nums[j]);
            
            if(maxElements.front() - minElements.front() > limit){
                if(maxElements.front() == nums[i]) maxElements.pop_front();
                if(minElements.front() == nums[i]) minElements.pop_front();
                i++;
            }
        }
        
        return j-i;
    }
};
