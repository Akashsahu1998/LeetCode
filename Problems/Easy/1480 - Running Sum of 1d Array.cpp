
// Question) 1480. Running Sum of 1d Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

vector<int> runningSum(vector<int>& nums) {
    for(int itr = 1; itr < nums.size(); itr++){
        nums[itr] += nums[itr-1];
    }
    return nums;
}


// 2nd Approach in Jav
// Time Complexity = O(N), Space Complexity = O(1)

public int[] runningSum(int[] nums) {
    for(int itr = 1; itr < nums.length; itr++){
        nums[itr] += nums[itr-1];
    }
    return nums;
}
