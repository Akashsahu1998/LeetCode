
// Question) 2129. Capitalize the Title


// Implementation

// Using stringstream
// Time Complexity = O(N), Space Complexity = O(Number of words)
class Solution {
public:
    string capitalizeTitle(string title) {
        string word;
        stringstream ss(title);
        string res = "";
        
        while (ss >> word){
            // convert a word into lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);            
            
            // if word size is more than 2, then convert first letter to uppercase
            if(word.size() > 2) word[0] = toupper(word[0]);
            res += word + " ";            
        }
        
        // removing the last space
        res.pop_back();         
        return res;
    }
};
