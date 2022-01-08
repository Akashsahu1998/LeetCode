
// Question) 2131. Longest Palindrome by Concatenating Two Letter Words


// Implementation

// Using matrix
// Time Complexity = O(N), Space Complexity = O(26*26) which is constant so O(1)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        
        // taking a matrix as a map
        vector<vector<int>> mat(26, vector<int>(26, 0));
                
        for(int itr = 0; itr < words.size(); itr++){
            int x = words[itr][0] - 97;
            int y = words[itr][1] - 97;
            
            // if reverse of ith word is already present than increment ans by 4, and make decrease the frequency of reverse by 1;
            if(mat[y][x]){
                ans += 4;
                mat[y][x]--;
            }
            else mat[x][y]++;   // if not reverse of ith word is not present then normally increment the word by 1;
        }
                
        for(int itr = 0; itr < 26; itr++){
            
            // this case is for examples like, ["gg", "cc", "ll"]
            if(mat[itr][itr]){
                ans += 2;
                break;
            }
        }
        
        return ans;
    }
};
