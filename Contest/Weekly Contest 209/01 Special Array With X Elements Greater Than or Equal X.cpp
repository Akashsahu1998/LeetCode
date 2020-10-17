
Q.) 1608. Special Array With X Elements Greater Than or Equal X

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count;
        for(int itr = 1; itr <= nums.size(); itr++){
            count = 0;
            for(int jtr = 0; jtr < nums.size(); jtr++){
                if(nums[jtr] >= itr){
                    count++;
                }                
            }
            if(count == itr) return itr;
        }
        return -1;
    }
};
