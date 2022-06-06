
// Question) 1143. Longest Common Subsequence


// Implementation

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2^n)
// Space Complexity : O(2^n)

class Solution {
private:
    int dfs(string &text1, string &text2, int index1, int index2){
        if(index1 < 0 || index2 < 0) return 0;
        
        if(text1[index1] == text2[index2]){
            return 1 + dfs(text1, text2, index1-1, index2-1);
        }
        
        return max(dfs(text1, text2, index1-1, index2), dfs(text1, text2, index1, index2-1));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        return dfs(text1, text2, m-1, n-1);
    }
};
