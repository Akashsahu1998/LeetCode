
// Question) 1436. Destination City

// Implementation
// Time Complexity = O(N)


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {        
        map<string, int> mp;
        string str1, str2;       
        
        for(int itr1 = 0 ; itr1 < paths.size(); itr1++){
            str1 = paths[itr1][0];
            str2 = paths[itr1][1];
            mp[str1] = 1;
            if(mp[str2] == 0) mp[str2] = 0;                
        }

        string res;

        for(auto a : mp){
            if(a.second == 0){         
                res = a.first;
                break;
            } 
        }
        return res;
    }
};
