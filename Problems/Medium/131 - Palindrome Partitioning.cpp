
// Question) 131. Palindrome Partitioning


// Implementation

// 1st Approach
// Using DFS, Backtracking
// Time Complexity = O(2^N)
// Space Complexity = O(N), not considering 2-D vector, bcz that's a part of output
class Solution {
public:
    bool isPallindrome(int start, int end, string str){
        while(start < end){
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }
    
    void findPartition(int index, string str, vector<string> &path, vector<vector<string>> &res) {
        if(index == str.size()){
            res.push_back(path);
            return;
        }
        
        for(int itr = index; itr < str.size(); itr++){
            if(isPallindrome(index, itr, str)){                
                path.push_back(str.substr(index, itr - index + 1));
                findPartition(itr+1, str, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        vector<vector<string>> res;
        vector<string> path;
        findPartition(0, str, path, res);
        return res;
    }
};



// 2nd Approach
// Using DFS & Backtracking
// Time Complexity = O(2^n)
// Space Complexity = O(N), not considering 2-D vector, bcz that's a part of output
class Solution {
public:
    
    bool isPallindrome(string str){
        int left = 0, right = str.size()-1;        
        while(left < right){
            if(str[left++] != str[right--]) return false;
        }
        return true;
    }
    
    void findPartition(vector<vector<string>> &res, vector<string> path, string str){
        if(!str.size()){
            res.push_back(path);
            return;
        }
        
        for(int itr = 0; itr < str.size(); itr++){
            string tempStr = str.substr(0, itr+1);
            string ros = str.substr(itr+1);
            
            if(isPallindrome(tempStr)){
                path.push_back(tempStr);
                findPartition(res, path, ros);
                path.pop_back();    // backtracking
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        vector<vector<string>> res;
        vector<string> path;
        findPartition(res, path, str);
        return res;
    }
};


// Understanding Time Complexity 
// In the worst case (string is all equal characters, eg "aaaaaaa"), the DP solution depends on the previous solutions, which means the result space is

// f(n) = f(n-1) + f(n-2) + ... + f(1)
// f(n+1) = f(n) + f(n-1) + f(n-2) + ... + f(1)= 2*f(n)
// f(n+1)/f(n) = 2
// So, it's exponential O(2^n)
