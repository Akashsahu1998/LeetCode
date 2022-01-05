
// Question) 131. Palindrome Partitioning


// Implementation

// DFS, Backtracking
// Time Complexity = O(N^2), Space Complexity = O(N), not considering 2-D vector, bcz that's a part of output
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
