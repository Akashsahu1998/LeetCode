
// Question) 41. First Missing Positive


// Implementation

// Using array as a map
// Time Complexity = O(N),
// Space Complexity = O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n+2, 0);
        
        for(int itr = 0; itr < n; itr++){
            if(nums[itr] >= 0 && nums[itr] <= n){
                mp[nums[itr]]++;
            }
        }
        
        for(int itr = 1; itr <= n+1; itr++){
            if(mp[itr] == 0) return itr;
        }
        
        return -1;
    }
};
