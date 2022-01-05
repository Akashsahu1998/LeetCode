
// Question) 132. Palindrome Partitioning II


// Implementation

// 1st
// Using Gap & Cut Strategy
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


// 2nd
// Using Gap & Cut Strategy
// Efficient Approach
// Time Complexity = O(N^2), Space Complexity = O(N^2)
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
        
        // using suffix technique
        vector<int> res(n);
        res[0] = 0;     // first char will always be pallindrome
        
        for(int itr = 1; itr < n; itr++){
            if(dp[0][itr]) res[itr] = 0;
            else{
                int minCut = INT_MAX;
                
                for(int jtr = itr; jtr >= 1; jtr--){                    
                    // if its pallindrome then only, we can find how many cut we can make
                    if(dp[jtr][itr]){
                        minCut = min(minCut, res[jtr-1]);
                    }
                }
                res[itr] = minCut + 1;  // +1 bcz we are making cut on current char as well
            }
        }
        
        // returning the last index of the res
        return res[n-1];
    }
};


// 3rd
// Using Gap & Cut Strategy
// Most Efficient Approach
// Time Complexity = O(N^2), Space Complexity = O(N^2)
class Solution {
public:
    int minCut(string str) {
        int n = str.size();
        
        // for gap strategy
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> res(n);
        
        // using prefix technique
        for(int itr = 0; itr < n; itr++){
            int minValue = itr;
            
            for(int jtr = 0; jtr <= itr; jtr++){
                
                if(str[itr] == str[jtr] && (itr-jtr<3 || dp[jtr+1][itr-1])){
                    dp[jtr][itr] = true; 
                    minValue = (jtr == 0) ? 0 : min(minValue, res[jtr-1]+1);
                }
            }
            
            res[itr] = minValue;
        }
        
        // returning the last index of the res
        return res[n-1];
    }
};
