
// Question) 17. Letter Combinations of a Phone Number


// Implementation

// 1st Approach
// Using DFS, Hashing & Backtracking
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



// 2nd Approach
// Using BFS & Hashing
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;        
        if(digits.size() == 0) return ans;
        
        ans.push_back("");
        
        // map the letters with the index(consider it as a number on the keypad)
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // iterating over the digits
        for(auto digit : digits){
            vector<string> temp;
            
            // finding the index of the digit present into digits, and taking the letters present over that particular index into the mapping
            string str = mapping[digit - '0'];
            
            // iterating over the characters of the letter for particular key
            for(auto ch :  str){
                
                // iterating over the ans
                for(auto res : ans){
                    temp.push_back(res + ch);
                }
            }
            
            // swapping the temp and ans, basically wanted to put temp into result
            swap(ans, temp);
        }
        
        return ans;
    }
};
