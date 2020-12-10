
// Q1.) 1668. Maximum Repeating Substring

// Implementation


// 1st Approach

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string newWord = word;
        while(sequence.find(newWord) != string::npos)
        {
            res++;
            newWord += word;
        }
        return res;
    }
};


// 2nd Approach

class Solution {
public:
    int maxRepeating(string sequence, string word) {        
        int sequenceLen = sequence.length(), wordLen = word.length(), res = 0; 
        int flag = 0, maxRes = 0;
        for (int i = 0; i <= sequenceLen - wordLen; ){  
            int j; 
            for (j = 0; j < wordLen; j++) {
                if (sequence[i+j] != word[j]) break;                     
            }                
            
            if (j == wordLen){
                flag = 1;     
                res++;
                maxRes = max(maxRes, res);
                i += wordLen;
            }
            else{
                if(flag == 1) i -= wordLen;                
                flag = 0;                    
                res = 0;                
                i++;                
            }
        } 
        return maxRes; 
    }
};
