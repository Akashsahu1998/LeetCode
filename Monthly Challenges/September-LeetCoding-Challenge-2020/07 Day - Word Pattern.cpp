class Solution {
public:
    bool wordPattern(string pattern, string str) {            
        stringstream ss(str);
        vector<string> vec;
        
        while(!ss.eof()) {
            string str;
            ss >> str;
            vec.push_back(str);
        }
        
        map<char,set<string>> mp;
        if(vec.size() != pattern.length()) return false;
    
        for(int itr = 0; itr < vec.size(); itr++)
            mp[pattern[itr]].insert(vec[itr]);
        
        for(auto it : mp)
            if(it.second.size() > 1) return false;
        
        map<string,set<char>> mp1;
        for(int itr = 0; itr < vec.size(); itr++)
            mp1[vec[itr]].insert(pattern[itr]);
        
        for(auto it : mp1) 
            if(it.second.size() > 1) return false;
        return true;        
    }
};
