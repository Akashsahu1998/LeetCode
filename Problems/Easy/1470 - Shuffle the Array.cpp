
// Question) 1470. Shuffle the Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> resultArray;        
    for(int itr = 0, jtr = nums.size()/2; jtr < nums.size(); itr++, jtr++){
        resultArray.push_back(nums[itr]);
        resultArray.push_back(nums[jtr]);
    }
    return resultArray;
}
