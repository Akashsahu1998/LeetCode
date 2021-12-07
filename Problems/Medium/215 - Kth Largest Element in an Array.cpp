
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


// 2nd Approach
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


// 3rd Approach
// Using Bubble Sort
// Time Complexity = O(N*K), Space Complexity = O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int itr = 0; itr < k; itr++){
            for(int jtr = 0; jtr < nums.size()-itr-1; jtr++){
                if(nums[jtr] > nums[jtr+1]){
                    int temp = nums[jtr];
                    nums[jtr] = nums[jtr+1];
                    nums[jtr+1] = temp;
                }
            }            
        }
        return nums[nums.size()-k];
    }
};
