
// Question) 283. Move Zeroes


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

void moveZeroes(vector<int>& nums) {    
    for(int itr = 0, jtr = 0; jtr < nums.size(); itr++){
        if(itr > nums.size()-1) nums[jtr++] = 0;
        else if(nums[itr] != 0) nums[jtr++] = nums[itr];
    }
}
