
// Question) 215. Kth Largest Element in an Array


// Implementation

// 1st Approach
// Using Sorting
// Time Complexity = O(NLogN), Space Complexity = O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};


// 1st Approach
// Using Priority Queue
// Time Complexity = O(NLogN), Space Complexity = O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
	    for(int itr = 1; itr < k; itr++) pq.pop();
	    return pq.top();
    }
};
