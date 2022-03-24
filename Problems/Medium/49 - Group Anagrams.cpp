
// Question) 49. Group Anagrams


// Implementation

// Using Unordered Map & Custom Sorting (Counting Sort)
// Time Complexity = O(N * 26)
// Space Complexity = O(N), Where N is the length of the given strs array

class Solution {
private:
    string sort(string str){
        
        // to store the frequency of the characters
        int freq[26] = {0};
        
        // finding the frequency of the characters
        for(auto ch : str){
            freq[ch - 'a']++;
        }
        
        // this will store the string, which will be in the sorted format
        string sortedStr;
                
        for(int itr = 0; itr < 26; itr++){
            
            // freq[itr] will give the frequency of a characters starting from a, b, c...
            // 'a' + itr will give the ascii value of the characters, like 97, 98, 99...
            // string(1st, 2nd), 1st argument will tell the how many char we need to add, for ex
            // string(2, 99) so it will do cc, here 99 got converted into c
            // string(5, 97) so it will do aaaaa, here 97 got converted into a
            sortedStr += string(freq[itr], 'a' + itr);
        }
        
        return sortedStr;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // traversing overs the strs array        
        for(auto str : strs){
            
            // for each strs array value we are sorting it using frequency and once sorting is done we are pushing the str into for the sorted key, so all keys will be in sorted and they will be having the values as a array of str
            mp[sort(str)].push_back(str);
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
