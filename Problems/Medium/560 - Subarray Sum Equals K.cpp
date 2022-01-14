
// Question) 560. Subarray Sum Equals K


// Implementation

// Using PreSum & Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        // putting 0 frequency as 1 for this case i.e [3]
        mp[0] = 1;
        int sum = 0, count = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            
            // calculating the presum
            sum += nums[itr];
            
            // calculating the remaining sum
            int remainingSum = sum - k;
            
            // if that remaining sum is already present then adding the frequency otherwise 0 will get add
            count += mp[remainingSum];
            
            // increases the frequence of sum in the map
            mp[sum]++;
        }
        
        return count;
    }
};
