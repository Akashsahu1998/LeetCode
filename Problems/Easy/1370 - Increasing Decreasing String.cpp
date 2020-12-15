
// Question) 1370. Increasing Decreasing String

// Implementation

class Solution {
public:
    string sortString(string s) {
        sort(s.begin(), s.end()); 
        
        string res = "";
        int index = 0;
        
        while(index < s.size()){
            char lastCh = ' ';
            for(int itr = 0; itr < s.size(); itr++){
                if(s[itr] != '\0'){
                    if(lastCh == ' '){
                        lastCh = s[itr];
                        index++;
                        res = res + s[itr];
                        s[itr] = '\0';
                    }
                    else if(lastCh < s[itr]){
                        lastCh = s[itr];
                        index++;
                        res = res + s[itr];
                        s[itr] = '\0';
                    }
                }    
            }
            
            lastCh = ' ';
            for(int itr = s.size()-1; itr >= 0; itr--){
                if(s[itr] != '\0'){
                    if(lastCh == ' '){
                        lastCh = s[itr];
                        index++;
                        res = res + s[itr];
                        s[itr] = '\0';
                    }
                    else if(lastCh > s[itr]){
                        lastCh = s[itr];
                        index++;
                        res = res + s[itr];
                        s[itr] = '\0';
                    }
                }
            }
        }
        
        return res;
    }
};
