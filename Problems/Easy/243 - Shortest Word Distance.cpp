
// Question) 243. Shortest Word Distance


// Implementation

// 1st Approach
// Time Complexity = O(N * M), Where N is the total words present into wordsDict, and M is the size of the word, bcz we are checking the string are equal or not
// Space Complexity = O(1)

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1Index = -1, word2Index = -1, minDistance = wordsDict.size();
        
        for(int i = 0; i < wordsDict.size(); i++){
            
            // if word1 found, then replace the word1Index
            if(wordsDict[i] == word1){
                word1Index = i;
            }   
            // if word2 found, then replace the word2Index
            else if(wordsDict[i] == word2){
                word2Index = i;
            }
            
            // if both index are not -1, then put the minimum value, 
            // if minDistance is already having min value, then don't replace it, that's why taking min method
            if(word1Index != -1 && word2Index != -1){
                minDistance = min(minDistance, abs(word1Index - word2Index));
            }
        }
        
        // return result
        return minDistance;
    }
};
