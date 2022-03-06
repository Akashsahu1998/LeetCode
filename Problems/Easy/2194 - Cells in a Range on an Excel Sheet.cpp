
// Question) 2194. Cells in a Range on an Excel Sheet


// Implementation

// Simple Brute Force, 2 For Loop
// Time Complexity: In worst case, it can be at most 26 * 9
// Space Complexity: O(1)
class Solution {
public:
    vector<string> cellsInRange(string s) {   
        
        // to store the result
        vector<string> res;
        
        // outer for loop to iterate over the letter, i.e K, L, M... in this way
        // inner for loop to iterate over the number, i.e 1, 2, 3... in this way        
        for(char letter = s[0]; letter <= s[3]; letter++){
            for(char num = s[1]; num <= s[4]; num++){
                
                // we are creating a temp string of the combination of letter and number and storing into res
                string temp = "";
                temp.push_back(letter);
                temp.push_back(num);
                res.push_back(temp);
            }
        }
        
        // return the res
        return res;
    }
};

