class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        int cnt = 0;
        bool flag;
        for(int itr = 0; itr < len; itr++){
            if(word[itr] >= 65 && word[itr] <= 90){
                cnt++;
            }
        }
        if(cnt == 0) flag = true;
        else if(cnt == len) flag = true;
        else if(cnt == 1 && (word[0] >= 65 && word[0] <= 90)) flag = true;
        else flag = false;  
        return flag;
    }
};
