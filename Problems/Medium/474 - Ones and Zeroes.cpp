
// Question) 474. Ones and Zeroes


// Implementation

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2! * N) => O(2!), Where N is the average length of the string
// Space Complexity : O(L), Where L is the length of the strs vector

class Solution {
private:
    void countZeroesAndOnes(string str, int &cnt0, int &cnt1){
        for(auto ch : str){
            if(ch == '0') cnt0++;
            if(ch == '1') cnt1++;
        }
    }
    
    int recursive(vector<string>& strs, int index, int m, int n){
        // base case
        if(index == strs.size()) return 0;
        
        int cnt0 = 0, cnt1 = 0;
        string str = strs[index];
        countZeroesAndOnes(strs[index], cnt0, cnt1);
    
        int notPick = recursive(strs, index+1, m, n);        
        int pick = INT_MIN;
        if(cnt0 <= m && cnt1 <= n){
            pick = 1 + recursive(strs, index+1, m - cnt0, n - cnt1);
        }
        
        return max(notPick, pick);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return recursive(strs, 0, m, n);
    }
};



// 2nd Approach
// Using Memoization Approach
// Time Complexity : O(L * M * N)
// Space Complexity : O(L * M * N), Where O(L) is coming from recursion stack trace

class Solution {
private:
    void countZeroesAndOnes(string str, int &cnt0, int &cnt1){
        for(auto ch : str){
            if(ch == '0') cnt0++;
            if(ch == '1') cnt1++;
        }
    }
    
    int recursive(vector<string>& strs, int index, int m, int n, vector<vector<vector<int>>> &memo){
        // base case
        if(index == strs.size()) return 0;
        
        if(memo[index][m][n] != -1) return memo[index][m][n];
        
        int cnt0 = 0, cnt1 = 0;
        string str = strs[index];
        countZeroesAndOnes(strs[index], cnt0, cnt1);
    
        int notPick = recursive(strs, index+1, m, n, memo);        
        int pick = INT_MIN;
        if(cnt0 <= m && cnt1 <= n){
            pick = 1 + recursive(strs, index+1, m - cnt0, n - cnt1, memo);
        }
        
        return memo[index][m][n] = max(notPick, pick);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>> (m+1, vector<int>(n+1, -1)));
        return recursive(strs, 0, m, n, memo);
    }
};




// 3rd Approach
// Using DP Approach
// Time Complexity : O(L * M * N)
// Space Complexity : O(M * N)

class Solution {
private:
    void countZeroesAndOnes(string str, int &cnt0, int &cnt1){
        for(auto ch : str){
            if(ch == '0') cnt0++;
            if(ch == '1') cnt1++;
        }
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for(auto str : strs){
            
            int cnt0 = 0, cnt1 = 0;
            countZeroesAndOnes(str, cnt0, cnt1);
            
            for(int j = m; j >= cnt0; j--){
            
                for(int k = n; k >= cnt1; k--){
                    dp[j][k] = max(dp[j][k], 1 + dp[j - cnt0][k - cnt1]);
                }                
            }            
        }
        
        return dp[m][n];
    }
};
