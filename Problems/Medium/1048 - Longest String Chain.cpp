
// Question) 1048. Longest String Chain


// Implementation

// Using DP
// Time Complexity : O(NlogN + N*L^2) => N (logN + L^2);
// Space Complexity : O(N)
// where N is the total number of strings into words and L is word.size();
// Dry run it, eventually we will understand the intitution and the code

class Solution {
private:
    bool static comp(string &word1, string &word2){
        return word1.size() < word2.size();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        
        // sort the array by string sizes
        sort(words.begin(), words.end(), comp);
        
        // store the string and the longest possible word chain length
        unordered_map<string, int> dp;
        
        int maxLength = 0;
        
        for(auto word : words){
            int presentLength = 1;
            
            for(int i = 0; i < word.size(); i++){
                
                // word = abcd, our i is at 2, so (ab + d) this is predecessor.
                string predecessor = word.substr(0, i) + word.substr(i+1);
                
                if(dp.find(predecessor) != dp.end()){
                    int previousLength = dp[predecessor];
                    presentLength = max(presentLength, previousLength+1);
                }
            }
            dp[word] = presentLength;
            maxLength = max(maxLength, presentLength);
        }
        
        return maxLength;
    }
};
