
// Question) 229. Majority Element II


// Implementation

// Using Boyer-Moore Voting Algorithm
// In this que max 2 cadidate can be a majority element
// Time Complexity = O(N),
// Space Complexity = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // putting INT_MIN, to handle the base case, i.e = [0,0,0] and [-1,-1,-1]
        int cadidate1 = INT_MIN, cadidate2 = INT_MIN, count1 = 0, count2 = 0;
        
        for(auto a : nums){
            if(cadidate1 == a){    // if candidate1 is already present, then just increase its frequency
                count1++;
            }
            else if(cadidate2 == a){    // if candidate2 is already present, then just increase its frequency
                count2++;
            }
            else if(count1 == 0){    // if the count1 is 0, then put the first candidate, and increase count1 by 1
                cadidate1 = a;
                count1 = 1;
            }
            else if(count2 == 0){   // if the count2 is 0, then put the second candidate, and increase count2 by 1
                cadidate2 = a;
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
            if(a == cadidate1) count1++;
            if(a == cadidate2) count2++;
        }
        
        // any count if more than n/3, then we will add that candidate into res
        vector<int> res;
        if(count1 > nums.size()/3) res.push_back(cadidate1);
        if(count2 > nums.size()/3) res.push_back(cadidate2);
        
        return res;
    }
};
