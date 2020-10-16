
// Simple Approach
// Time Complexity = O(N)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ansCount = 0, flag = 0;;        
        for(int itr = s.size() - 1; itr >= 0;itr--) {
            if(s[itr] == ' ' && flag == 1) break;
            else if(s[itr] != ' ') {
                ansCount++;
                flag = 1;
            }           
        }
        return ansCount;
    }
};
