
// Question) 300. Longest Increasing Subsequence


// Implementation


// Naive Approach
// Using DP
// Time Complexity : O(N^2)
// Space Complexity : O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // creating dp with value 1 in all index, bcz all element will have their own size as 1 atleast
        vector<int> dp(nums.size(), 1);
        
        // intializing with 1 bcz atleast 1 length it will have
        int longestLength = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                    longestLength = max(longestLength, dp[i]);
                }
            }
        }
        
        return longestLength;
    }
};


// Efficient Approach
// Using Binary Search
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

// In this approach our SortedArr will have a longest increasing subsequence as well, later we can print that as well if we need

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> sortedArr(nums.size());
        
        // intializing with 1 bcz atleast 1 length it will have
        int size = 0;
        for(auto num : nums){
            int low = 0, high = size;
            
            while(low < high){
                int mid = low + (high-low)/2;
                
                if(sortedArr[mid] < num){
                    low = mid+1;
                }
                else high = mid;
            }
            
            sortedArr[low] = num;
            if(low == size) size++;
        }
        
        return size;
    }
};


// Algo Steps
// 1) In this approach our SortedArr will have a longest increasing subsequence as well, later we can print that as well if we need
// 2) Take one size var & Iterate over the org arr, & use binary search inside that

