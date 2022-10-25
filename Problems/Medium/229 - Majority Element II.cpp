
// Question) 229. Majority Element II


// Implementation

// Using Boyer-Moore Voting Algorithm
// In this que max 2 candidate can be a majority element
// Time Complexity = O(N),
// Space Complexity = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN, count1 = 0, count2 = 0;        
        
        for(auto a : nums){
            if(candidate1 == a){    // if candidate1 is already present, then just increase its frequency
                count1++;
            }
            else if(candidate2 == a){    // if candidate2 is already present, then just increase its frequency
                count2++;
            }
            else if(count1 == 0){    // if the count1 is 0, then add put the first candidate, and increase count1 by 1
                candidate1 = a;
                count1 = 1;
            }
            else if(count2 == 0){   // if the count2 is 0, then add put the second candidate, and increase count2 by 1
                candidate2 = a;
                count2 = 1;
            }
            else{   // if new candidate is coming, then decrease both already existing cadidate frequency by 1
                count1--;
                count2--;
            }
        }
        
        // once we get the cadidate's for two majority element we will again count the total occurence of both cadidate's into an array
        count1 = 0, count2 = 0;
        for(auto a : nums){
            if(a == candidate1) count1++;
            if(a == candidate2) count2++;
        }
        
        // any count if more than n/3, then we will add that candidate into res
        vector<int> res;
        if(count1 > nums.size()/3) res.push_back(candidate1);
        if(count2 > nums.size()/3) res.push_back(candidate2);
        
        return res;
    }
};


// Algo Steps:
// 1) In this que max 2 candidate can be a majority element
// 2) Take 2 counts and 2 candidates for majority element, and do solve it
