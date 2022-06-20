
// Question) 244. Shortest Word Distance II


// Implementation

// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N)

class WordDistance {
private:
    unordered_map<string, vector<int>> mp;
    
public:
    // O(N)
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++){
            mp[wordsDict[i]].push_back(i);
        }
    }
    
    // O(K + L), Where K is the size of wordIndex1 and L is the size of wordIndex2
    // i.e 
    // word1 = [1 3 5 7 9]
    // word2 = [2 4 6 8 10]
    // in this case we need to traverse both array's fully, so T.C is O(K + L)
    int shortest(string word1, string word2) {
        vector<int> wordIndex1 = mp[word1];
        vector<int> wordIndex2 = mp[word2];
        
        int index1 = 0, index2 = 0, minDistance = INT_MAX;
        while(index1 < wordIndex1.size() && index2 < wordIndex2.size()){
            minDistance = min(minDistance, abs(wordIndex1[index1] - wordIndex2[index2]));
            
            if(wordIndex1[index1] < wordIndex2[index2]){
                index1++;
            }
            else index2++;
        }
        
        return minDistance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
