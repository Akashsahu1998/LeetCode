
// Question) 49. Group Anagrams


// Implementation

// 1st Approach
// Using Unordered Map & Sorting
// Time Complexity = O(N * M*logM), where M is the length of the particular string present into the strs array, and N is the length of the given strs array
// Space Complexity = O(N), Where N is the length of the given strs array

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // traversing overs the strs array        
        for(auto str : strs){
            
            // for each strs array value we are sorting it and once sorting is done we are pushing the str into sorted key(val), so all keys will be in sorted and they will be having the values as a array of str
            string val = str;
            sort(val.begin(), val.end());
            mp[val].push_back(str);
        }
        
        // for storing the res
        vector<vector<string>> res;
        
        // traversing over the map, and pushing the values of the pair(key, value) into res
        for(auto values : mp){
            res.push_back(values.second);
        }
        
        return res;
    }
};
