
Q1.) 1662. Check If Two String Arrays are Equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "", str2 = "";
        
        for(int itr = 0; itr < word1.size(); itr++){
            str1 = str1 + word1[itr];  
        }
        
        for(int itr = 0; itr < word2.size(); itr++){
            str2 = str2 + word2[itr];
        }
        
        if(str1 == str2) return true;
        else return false;        
    }
};


