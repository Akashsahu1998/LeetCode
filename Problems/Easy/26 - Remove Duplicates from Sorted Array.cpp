
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



// 2nd Approach
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int index = 1;
        for(int itr = 1; itr < nums.size(); itr++){
            if(nums[itr] != nums[itr-1]) nums[index++] = nums[itr];            
        }
        return index;
    }
};
