
// Q1.) 1668. Maximum Repeating Substring

// Implementation
// Time Complexity = O(M * N)


class Solution {
public:
    int maxRepeating(string sequence, string word) {        
        int sequenceLen = sequence.length(), wordLen = word.length(), res = 0; 
        
        for (int i = 0; i <= sequenceLen - wordLen; i++){  
            int j; 
            for (j = 0; j < wordLen; j++) {
                if (sequence[i+j] != word[j])  break;                     
            }                
            
            if (j == wordLen){ 
               res++; 
               j = 0; 
            } 
        } 
        return res; 
    }
};


