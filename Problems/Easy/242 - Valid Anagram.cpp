
// Question) 242. Valid Anagram


// Implementation

// Using Frequency Array
// Time Complexity: O(N)
// Space Complexity: O(1), as we are taking 26 char arr, thats why it will be cosidered as a constant space

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        vector<int> arr(26, 0);
        
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        
        for(auto a : arr){
            if(a != 0) return false;
        }
        
        return true;
    }
};
