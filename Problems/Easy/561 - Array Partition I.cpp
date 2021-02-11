
// Question) 561. Array Partition I


// Implementation

// 1st Approach in C++
// Time Complexity = O(NLogN), Space Complexity = O(1)

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for(int itr = 0; itr < nums.size(); itr += 2){
        result += nums[itr];
    }
    return result;
}


// 2nd Approach in Java
// Time Complexity = O(NLogN), Space Complexity = O(1)

public int arrayPairSum(int[] nums) {
    Arrays.sort(nums);
    int result = 0;
    for(int itr = 0; itr < nums.length; itr += 2){
        result += nums[itr];
    }
    return result;
}
