
// Question) 525. Contiguous Array


// Implementation

// Using unoredered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0, sum = 0;
        unordered_map<int, int> mp;
        
        // replacing 0 by -1
        for(int itr = 0; itr < nums.size(); itr++){
            nums[itr] = (nums[itr] == 0) ? -1 : 1;
        }
        
        for(int itr = 0; itr < nums.size(); itr++){
            
            // calculating the sum on each index
            sum += nums[itr];
            
            // To handle sum = 0 at last index, i.e = 0 0 1 1
            if(sum == 0){
                maxLength = itr+1;
            }
            
            // if sum is already in the map, then just calculate the maximum length of the subarray
            // if sum is not present then just add it into the map with the value as a index, so later on, that index will help us to find the maximum length
            if(mp.find(sum) != mp.end()){
                maxLength = max(maxLength, itr - mp[sum]);
            }
            else mp[sum] = itr;
        }
        
        return maxLength;
    }
};
