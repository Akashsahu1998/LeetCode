
// Question) 485. Max Consecutive Ones


// Implementation

// Single Pass
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0, consecutiveOnes = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                maxConsecutiveOnes = max(maxConsecutiveOnes, consecutiveOnes);
                consecutiveOnes = 0;
            }
            else{
                consecutiveOnes++;
            }
        }
        maxConsecutiveOnes = max(maxConsecutiveOnes, consecutiveOnes);
        return maxConsecutiveOnes;
    }
};
