
// Question) 132. Palindrome Partitioning II


// Implementation

// Using Gap Strategy
// Will give TLE
// Naive Approach
// Time Complexity = O(N^3), Space Complexity = O(N^2)
class Solution {
public:
    int minCut(string str) {
        int n = str.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
                
        for(int gap = 0; gap < n; gap++){
            for(int itr = 0, jtr = gap; jtr < n; itr++, jtr++){
                if(gap == 0) dp[itr][jtr] = true;
                else if(gap == 1) dp[itr][jtr] = str[itr] == str[jtr];
                else{
                    if(str[itr] == str[jtr] && dp[itr+1][jtr-1]) dp[itr][jtr] = true;
                    else dp[itr][jtr] = false;
                }
            }
        }
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int gap = 0; gap < n; gap++){
            for(int itr = 0, jtr = gap; jtr < n; itr++, jtr++){                
                if(gap == 0) res[itr][jtr] = 0;
                else if(gap == 1) res[itr][jtr] = (dp[itr][jtr]) ? 0 : 1;
                else{
                    if(dp[itr][jtr]){
                        res[itr][jtr] = 0;
                    }
                    else{
                        int minValue = INT_MAX;                    
                        for(int ktr = itr; ktr < jtr; ktr++){
                            int left = res[itr][ktr];
                            int right = res[ktr+1][jtr];

                            minValue = min(minValue, left+right+1);
                        }

                        res[itr][jtr] = minValue;
                    }                    
                }
            }
        }
        
        // returning the last index of the first row
        return res[0][n-1];
    }
};
