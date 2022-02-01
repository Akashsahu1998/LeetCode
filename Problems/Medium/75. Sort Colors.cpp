
// Question) 75. Sort Colors


// Implementation

// 1st Approach
// Naive Approach
// Using the inbuilt sort function
// Time Complexity = O(NLogN)
// Space Complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};


// 2nd Approach
// Efficient Approach
// Traversing 2 times
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero = 0, countOne = 0, countTwo = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            if(nums[itr] == 0) countZero++;
            else if(nums[itr] == 1) countOne++;
            else countTwo++;
        }
        
        for(int itr = 0; itr < nums.size(); itr++){
            if(itr < countZero) nums[itr] = 0;
            else if(itr < countZero + countOne) nums[itr] = 1;
            else nums[itr] = 2;
        }
    }
};
