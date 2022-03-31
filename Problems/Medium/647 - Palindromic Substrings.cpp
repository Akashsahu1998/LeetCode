
// Question) 647. Palindromic Substrings


// Implementation

// 1st Approach
// Using DP, Gap Strategy
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size(); 
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int gap = 0; gap < n; gap++){
            for(int itr = 0, jtr = gap; jtr < n; itr++, jtr++){
                if(gap == 0){
                    dp[itr][jtr] = 1;
                }
                else if(gap == 1){
                    if(s[itr] == s[jtr]) dp[itr][jtr] = 1;
                }
                else{
                    if(s[itr] == s[jtr] && dp[itr+1][jtr-1]) dp[itr][jtr] = 1;
                }
                
                if(dp[itr][jtr]) ans++;
            }
        }
        
        return ans;
    }
};


// 2nd Approach
// Better than the 1st Approach, Without DP
// Time Complexity: O(N^2)
// Space Complexity: O(1)

// Idea: Simply iterating over the string and checking whether we can extend string as a pallindrome or not for odd & even length by moving left & right side


class Solution {
private:
    void tryToExtendPallindrome(string s, int left, int right, int &ans){
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
    }
    
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for(int itr = 0; itr < s.size(); itr++){
            // odd length
            tryToExtendPallindrome(s, itr, itr, ans);
            
            // even length
            tryToExtendPallindrome(s, itr, itr+1, ans);
        }
        
        return ans;
    }
};
