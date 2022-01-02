
// Question) 1010. Pairs of Songs With Total Durations Divisible by 60


// Implementation

// Using unordered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int itr = 0; itr < time.size(); itr++){
            int rem = time[itr] % 60;            
            
            // again (mod by 60) bcz, we are adding the rem into mp otherwise it will be an issue
            // i.e [60,60,60]
            res += mp[(60 - rem) % 60];     
            
            // incrementing rem bcz, we want mod value(not a nummber more than 59) only to add into 
            // time[itr] to make it Divisible by 60
            mp[rem]++;
        }
        
        return res;
    }
};
