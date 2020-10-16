// 1st Method
// Using Unordered Map

class Solution {
public:
    int longestPalindrome(string str) {
        unordered_map<char, int> charFreq;
        for(char ch : str) charFreq[ch]++;
        int flag = 0, lenOfStr = 0;      
        for(auto a : charFreq){
            if(flag == 0){
                if(a.second % 2 == 1){
                    flag = 1;
                    lenOfStr += 1;
                }
             }   
            if(a.second % 2 == 1) lenOfStr += a.second - 1;
            else lenOfStr += a.second;
            
        }
        return lenOfStr;
    }
};


// 2nd Method
// Without using Map or Unordered Map

class Solution {
public:
    int longestPalindrome(string str) {
        int charFreq[256] = {0};
        for(char ch : str) charFreq[ch]++;
        int flag = 0, lenOfStr = 0;      
        for(int itr : charFreq){
            if(flag == 0){
                if(itr % 2 == 1){
                    flag = 1;
                    lenOfStr += 1;
                }
             }   
            if(itr % 2 == 1) lenOfStr += itr - 1;
            else lenOfStr += itr;
        }
        return lenOfStr;
    }
};
