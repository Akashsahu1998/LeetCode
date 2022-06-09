
// Question) 72. Edit Distance


// Implementation

// https://www.youtube.com/watch?v=fJaKO8FbDdo

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2!)
// Space Complexity : O(2!)

class Solution {
private:
    int solve(string word1, string word2, int ptr1, int ptr2){
       
        if(ptr1 == -1 && ptr2 == -1) return 0;
        if(ptr1 == -1) return ptr2+1;
        if(ptr2 == -1) return ptr1+1;
        
        // if matching
        if(word1[ptr1] == word2[ptr2]){
            return solve(word1, word2, ptr1-1, ptr2-1);    
        }       
        
        // deleting char, hypothetically deleting, it means just decrementing ptr1
        int deleteChar = 1 + solve(word1, word2, ptr1-1, ptr2);
        
        // inserting char, hypothetically inserting, it means just decrementing ptr2
        int insertChar = 1 + solve(word1, word2, ptr1, ptr2-1);
        
        // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
        int replaceChar = 1 + solve(word1, word2, ptr1-1, ptr2-1);
        
        return min(deleteChar, min(insertChar, replaceChar));
    }
    
public:
    int minDistance(string word1, string word2) {
        // Assuming 0 based indexing
        return solve(word1, word2, word1.size()-1, word2.size()-1);
    }
};



// 2nd Approach
// Recursive DP Approach / Memoization
// Time Complexity : O(M * N)
// Space Complexity : O(M * N + M * N) => O(M * N), bcz of recursion stack trace

class Solution {
private:
    int solve(string word1, string word2, int ptr1, int ptr2, vector<vector<int>> &memo){
       
        if(ptr1 == 0 && ptr2 == 0) return 0;
        if(ptr1 == 0) return ptr2;
        if(ptr2 == 0) return ptr1;
        
        if(memo[ptr1][ptr2] != -1) return memo[ptr1][ptr2];
        
        // if matching
        if(word1[ptr1-1] == word2[ptr2-1]){
            return memo[ptr1][ptr2] = solve(word1, word2, ptr1-1, ptr2-1, memo);    
        }       
        
        // deleting char, hypothetically deleting, it means just decrementing ptr1
        int deleteChar = 1 + solve(word1, word2, ptr1-1, ptr2, memo);
        
        // inserting char, hypothetically inserting, it means just decrementing ptr2
        int insertChar = 1 + solve(word1, word2, ptr1, ptr2-1, memo);
        
        // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
        int replaceChar = 1 + solve(word1, word2, ptr1-1, ptr2-1, memo);
        
        return memo[ptr1][ptr2] = min(deleteChar, min(insertChar, replaceChar));
    }
    
public:
    int minDistance(string word1, string word2) {
        // Assuming 1 based indexing
        vector<vector<int>> memo(word1.size()+1, vector<int> (word2.size()+1, -1));
        return solve(word1, word2, word1.size(), word2.size(), memo);
    }
};
