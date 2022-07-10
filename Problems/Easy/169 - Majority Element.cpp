
// Question) 169. Majority Element


// Implementation

// Using Moore's Voting Algorithm
// Time Complexity = O(N),
// Space Complexity = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = 0, cntOfMajorityElement = 0;
        for(auto num : nums){
            // if cnt is going is becoming zero it means we got new element which is coming more time, and can be a candidate for majority
            if(cntOfMajorityElement == 0){
                majorityElement = num;
            }
            
            // if num is majorityElement, just increase the cntOfMajorityElement, otherwise decrease cntOfMajorityElement
            if(num == majorityElement) cntOfMajorityElement++;
            else cntOfMajorityElement--;
        }
        
        return majorityElement;
    }
};


// Algo steps
// 1) Use cnt & val var
// 2) whenever cnt is 0, then we got new ele
// 3) if val == curVariable, then increase the cnt, otherwise decrease it
