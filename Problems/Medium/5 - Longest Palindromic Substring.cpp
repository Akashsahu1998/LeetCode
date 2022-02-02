
// Question) 5. Longest Palindromic Substring


// Implementation

// Using Dynamic Programming
// Time Complexity = O(N^2)
// Space Complexity = O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        // result indexes
        int itrResult, jtrResult;
        
        // creating DP to store the result of previous substring
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        // using this loop as a gap strategy, gap between itr & jtr index for our string
        for(int gap = 0; gap < n; gap++){
            
            // starting itr from 0, and jtr from gap, so it will maintain the gap between the itr & jtr always
            for(int itr = 0, jtr = gap; jtr < n; jtr++, itr++){
                
                // if gap is 0, it means, its a single char, so its pallindrome, so we can put true into DP
                if(gap == 0){
                    dp[itr][jtr] = true;
                }
                else if(gap == 1){
                    // if gap is 1, it means, there are 2 chars, so if we will check the first char and second char, if both are equal then it means its pallindrome, so we can put true into DP, if not equal then we will put false
                    dp[itr][jtr] = (s[itr] == s[jtr]) ? true : false;
                }
                else{
                    // if gap is more than 1, so we will check the starting char with itr and ending char with jtr in string, if there values are equal and we will also check itr+1 and jtr-1, the result of rest of the string, in DP, if its true, then it means its pallindrome, otherwise not a pallindrome
                    
                    dp[itr][jtr] = (s[itr] == s[jtr] && dp[itr+1][jtr-1]) ? true : false;                    
                }
                
                // storing the value of itr and jtr index, for the result purpose
                // the dp[itr][jtr] which will be true in the last, that is our result, bcz
                // we are moving from 0 to n gap, so it means if we got the result in 3 gap, it means our longest substring is that, so we will store the resule
                if(dp[itr][jtr]){
                    itrResult = itr;
                    jtrResult = jtr;
                }
            }
        }
        
        // return the substr from itr of length (jtr-jtr+1)
        return s.substr(itrResult, jtrResult - itrResult + 1);
    }
};
