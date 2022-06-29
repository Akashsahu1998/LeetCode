
// Question) 249. Group Shifted Strings


// Implementation

// Using Unordered Map 
// Time Complexity : O(N * K), Where N is the length of the strings, and M is the length of the each string and for each string we are finding the hashValue
// Time Complexity : O(N * K), In the worst scenario, when each string in the given list belongs to a different Hash value, the maximum number of strings stored in mapHashToList is 2 * N. Each string takes at most O(K) space. Hence the overall space complexity is O(N * K).

class Solution {
private:
    char shiftChar(char shift, char ch){
        // adding 26 to avoid the negative values, bcz if ch < shift, then the value will come as a neg
        // by adding 26 it will round the value
        // in last adding 'a' bcz to typecase return value as a char, we can remove that 'a' as well, but then indirectly it will typecast into char while returning, so we can do manually as well by putting 'a', and we can convert int into char.
        return (ch - shift + 26) % 26 + 'a';
        // return (ch - shift + 26) % 26; this will also work
    }
    
    string getHashValueOfString(string str){
        char shift = str[0];
        string hashValue = "";
        for(auto ch : str){
            
            // shifting all char's by the same value as shfit
            hashValue += shiftChar(shift, ch);
        }
        return hashValue;
    }
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        
        // iterating over the strings and finding the hashValue for each string
        for(auto str : strings){
            string hashValue = getHashValueOfString(str);
            
            // storing the str for the generated hashValue
            mp[hashValue].push_back(str);
        }
        
        // adding the values of all generated hashValue into res
        vector<vector<string>> res;
        for(auto a : mp){
            res.push_back(a.second);
        }
        
        return res;
    }
};


// Algo Steps :
// 1) Iterate over the string
// 2) for each string, find the hashvalue
// 3) to find hashvalue, we need to take the first char as a shfit, and then shift all the char's by the same value shift, and also do the mod 26 for the circular shift.
// 4) take care of negative value while shifting of char's
