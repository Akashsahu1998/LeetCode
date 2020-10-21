
// 1st Approach

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string str) {
        int itr, jtr, maxStr = -1;        
        for(itr = 0; itr < str.size(); itr++){            
            for(jtr = str.size()-1; str[jtr] != str[itr]; jtr--){}
            maxStr = max(maxStr, jtr - itr - 1);
        }
        return maxStr;
    }
};



// 2nd Approach

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string str) {
        int Max = 0, cnt, flagNeg = 0, flag, temp, cntVar;
        for(int itr = 0; itr < str.size(); itr++){
            cnt = 0; flag = 0; cntVar = -1;
            for(int jtr = itr+1; jtr < str.size(); jtr++){
                if(str[itr] != str[jtr]) cnt++;
                else{
                    cntVar++;
                    temp = cnt;
                    flag = 1;
                }
            }
            if(flag == 1){
                flagNeg = 1;
                Max = max(Max, temp+cntVar);
            }
        }
        if(flagNeg == 0) return -1;        
        else return Max;
    }
};
