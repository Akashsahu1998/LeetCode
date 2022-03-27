
// Question) 2216. Minimum Deletions to Make Array Beautiful


// Implementation

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:    
    int minDeletion(vector<int>& nums) {
        int count = 0, size = 1, prevEle = nums[0];
        
        for(int itr = 1; itr < nums.size(); itr++){
            if(((size-1) % 2 == 0) && (prevEle == nums[itr])){
                count++;
                continue;
            }
            else {
                size++;
                prevEle = nums[itr];
            }
        }
                
        return (size % 2 == 1) ? count+1 : count;
    }
};
