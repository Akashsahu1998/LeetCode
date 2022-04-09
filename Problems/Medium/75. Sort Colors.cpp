
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



// 3rd Approach
// Most Efficient Approach
// Traversing 1 time
// Using 3 pointers
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        
        // traversing over the array with the help of mid, run until and unless mid become greater than high
        // checking over the mid only
        while(mid <= high){
            
            // if nums[mid] is 0, then swap low and mid values and increment low & mid by 1
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){    // if its 1, then increment mid by 1
                mid++;
            }
            else{    // if its 2, then swap mid and high values and decrement high by 1, not incrementing mid bcz nums[mid] may can have 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
