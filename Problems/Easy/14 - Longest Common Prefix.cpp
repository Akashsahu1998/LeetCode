
// Question) 14. Longest Common Prefix


// Implementation

// Using Sorting & Comparing two string
// Time Complexity : O(NLogN)
// Space Complexity : O(1)

// Idea: sort the vector, then compare char's of first string with last string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        
        // Sort the vector
        sort(strs.begin(), strs.end());
        
        // take start index string into str1, and last index string into str2
        string str1 = strs[0], str2 = strs[strs.size()-1];
        
        // take two var, itr will point to str1, and jtr will point to str2
        int itr = 0, jtr = 0;
        
        // store the result into ans
        string ans = "";
        
        // run the loop, till the time both str1 & str2 don't have different char, and simlutaneously store the result into ans
        while((itr < str1.size() && jtr < str2.size()) && (str1[itr] == str2[jtr])){
            ans += str1[itr];
            itr++, jtr++;
        }
        
        // return ans
        return ans;
    }
};
