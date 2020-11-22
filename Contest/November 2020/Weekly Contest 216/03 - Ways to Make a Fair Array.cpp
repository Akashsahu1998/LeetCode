
Q3.) 1664. Ways to Make a Fair Array

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0, eSum = 0, oSum = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            if(itr % 2 == 0) eSum += nums[itr];
            else oSum += nums[itr];     
        }
        
        int temp = 0;
        temp = eSum;
        eSum = oSum;
        oSum = temp;
        oSum = oSum - nums[0];
        
        int es = nums[0], os = 0;
        
        if(eSum == oSum) cnt++;
        
        for(int itr = 1; itr < nums.size(); itr++){
            if(itr % 2 == 1){
                eSum -= nums[itr];
                eSum += es;
                os = nums[itr];
            }
            else{
                oSum -= nums[itr];
                oSum += os;
                es = nums[itr];
            }
            
            if(eSum == oSum) cnt++;            
        }
				     
        return cnt;
    }
};
