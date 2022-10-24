
// Question) 118. Pascal's Triangle

// LC Solution : https://leetcode.com/problems/pascals-triangle/discuss/2738435/dp-simple-approach-comments-added-c

// Implementation

// Using DP, Using pre calculated rows to calculate next row
// Time Complexity = O(numRows ^ 2)
// Space Complexity = O(1)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        // base case
        res.push_back({1});
        if(numRows == 1) return res;
        
        // star from 2 till numRows
        for(int i = 2; i <= numRows; i++){
            
            // extract the last res, and use it to calculate the next row
            vector<int> cur = res[res.size()-1];
            
            vector<int> curRowRes;
            
            // the first row element will always be 1
            curRowRes.push_back(1);
            
            // creating the new values using last values and storing into new result
            for(int i = 0, j = 1; j < cur.size(); i++, j++){
                curRowRes.push_back(cur[i] + cur[j]);
            }
            
            // the last row element will always be 1
            curRowRes.push_back(1);
            
            // add cur rowRes into final res
            res.push_back(curRowRes);
        }
        
        return res;
    }
};
