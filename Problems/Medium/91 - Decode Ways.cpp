
// Question) 91. Decode Ways


// Implementation

// https://www.youtube.com/watch?v=jFZmBQ569So
// Using DP
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    int numDecodings(string s) {       
        
        vector<int> dp(s.size(), 0);
        if(s[0] != '0') dp[0] = 1;
        
        for(int itr = 1; itr < s.size(); itr++){
            
            if(s[itr-1] == '0' && s[itr] == '0'){
                dp[itr] = 0;
            }
            else if(s[itr-1] == '0' && s[itr] != '0'){
                dp[itr] = dp[itr-1];
            }
            else if(s[itr-1] != '0' && s[itr] == '0'){
                if(s[itr-1] == '1' || s[itr-1] == '2'){
                    dp[itr] = itr > 1 ? dp[itr-2] : 1;
                }
            }
            else{
                if(stoi(s.substr(itr-1, 2)) <= 26){
                    dp[itr] = dp[itr-1] + (itr > 1 ? dp[itr-2] : 1);
                }
                else{
                    dp[itr] = dp[itr-1];
                }
            }            
        }
        
        return dp[s.size()-1];
    }
};
