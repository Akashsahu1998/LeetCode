
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


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

 public int[] shuffle(int[] nums, int n) {
    int[] resultArray = new int[nums.length];        
    for(int itr = 0, jtr = nums.length/2, ktr = 0; jtr < nums.length; itr++, jtr++){            
        resultArray[ktr++] = nums[itr];
        resultArray[ktr++] = nums[jtr];
    }
    return resultArray;
}
