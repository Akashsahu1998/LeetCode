
// Question) 977. Squares of a Sorted Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(1)

vector<int> sortedSquares(vector<int>& nums) {
    for(int itr = 0; itr < nums.size(); itr++){
        nums[itr] = nums[itr]*nums[itr];
    }
    sort(nums.begin(), nums.end());
    return nums;
}


// 2nd Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res(nums.size());
    int low = 0, high = nums.size()-1;
    for(int itr = nums.size()-1; itr > -1; itr--){
        if(abs(nums[low]) > nums[high]){
            res[itr] = pow(nums[low], 2);
            low++;
        }
        else{
            res[itr] = pow(nums[high], 2);
            high--;
        }
    }
    return res;
}
