
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



// 2nd Approach
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
            
            // for each strs array value we are sorting it using frequency and once sorting is done we are pushing the str into the sorted key, so all keys will be in sorted and they will be having the values as a array of str
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



// Algo Steps
// 1) Sort all the strings and put into the map as a key(sorted string) & value(org str and also take vector as a value)
// 2) and iterate over the map, and put vector which is in value into the res(2-d array)
