
// Question) 26. Remove Duplicates from Sorted Array


// Implementation

// 1st Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {        
        int count = 0, n = nums.size();
        for(int itr = 0, index = 0; itr < n; itr++){
            while(itr+1 < n && nums[itr] == nums[itr+1]){
                itr++;
            }
            nums[index++] = nums[itr];
            count++;
        }
        return count;
    }
};
