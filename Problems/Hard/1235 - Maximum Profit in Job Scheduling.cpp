
// Question) 1235. Maximum Profit in Job Scheduling


// Implementation

// Using DP, Sorting & Binary Search
// Time Complexity = O(NLogN)
// Space Complexity = O(N)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        
        for(int i = 0; i < n; i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for(int i = 1; i < n; i++){
            int res = -1, low = 0, high = i-1, including = jobs[i][2];
            
            while(low <= high){
                int mid = (low+high) / 2;
                
                if(jobs[mid][0] <= jobs[i][1]){
                    res = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            
            if(res != -1){
                including += dp[res];
            }
            
            int excluding = dp[i-1];
            dp[i] = max(excluding, including);
        }
        
        return dp[n-1];
    }
};

/*
1) Firstly Sort by end time 
2) create dp
3) run loop from 1 to n
4) inside loop do binary search and check what and all we can take, we can include or exclude
*/
