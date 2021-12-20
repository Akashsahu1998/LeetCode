
// Question) 1679. Max Number of K-Sum Pairs


// Implementation

// Using Two Pointer Approach
// Time Complexity = O(NLogN), Space Complexity = O(1)
class Solution {
public:    
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0, itr = 0, jtr = nums.size()-1;
        while(itr < jtr){
            if(nums[itr] + nums[jtr] == k) {
                itr++;
                jtr--;
                count++;
            }
            else if(nums[itr] + nums[jtr] > k) jtr--;
            else itr++;
        }
        return count;
    }
};
