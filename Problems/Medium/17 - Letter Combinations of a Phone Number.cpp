
// Question) 17. Letter Combinations of a Phone Number


// Implementation

// 1st Approach
// Using Hashing & Backtracking
class Solution {
public:
    void makeCombinations(string digits, int index, string mapping[], string output, vector<string> &ans){
        if(index == digits.size()){
            ans.push_back(output);
            return;
        }
        
        // finding the index of the digit present into digits
        int indexOfMapping = digits[index] - '0';
        
        // taking the letters present over that particular index
        string letters = mapping[indexOfMapping];
        
        for(int itr = 0; itr < letters.size(); itr++){
            output.push_back(letters[itr]);
            makeCombinations(digits, index+1, mapping, output, ans);    
            
            // Backtracking
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;        
        if(digits.size() == 0) return ans;
        
        // map the letters with the index(consider it as a number on the keypad)
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        int index = 0;
        string output;
        
        makeCombinations(digits, index, mapping, output, ans);
        
        return ans;
    }
};
