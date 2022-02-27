
// Question) 2185. Counting Words With a Given Prefix


// Implementation

// Time Complexity: O(N * M), where N = words.size(), M = pref.size();
// Space Complexity: O(1)

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        
        for(auto word : words){
            string str = word;
            
            int itr = 0, jtr = 0, flag = 1;
            if(str.size() < pref.size()) continue;
            while(itr < str.size() && jtr < pref.size()){
                if(str[itr++] == pref[jtr++]) continue;
                flag = 0;
            }
            
            if(flag) {
                cout << str;
                cnt++;
            }
        }
        
        return cnt;
    }
};
