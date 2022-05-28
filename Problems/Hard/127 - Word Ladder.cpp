
// Question) 127. Word Ladder


// Implementation

// https://www.youtube.com/watch?v=jvTa0t3-GQo&t=353s
// BFS Approach
// Using Queue & Unordered Set
// Time Complexity = O(N * M * 26), Where N is the length of the wordList, M is the size of the word present into the wordList, and 26 means, from a to z we are running the loop
// Space Complexity = O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary;
        for(auto a : wordList){
            dictionary.insert(a);
        }
        
        // if end word didn't found, so it means we don't have any sequence
        if(dictionary.find(endWord) == dictionary.end()) return 0;
        
        // taking queue, bcz we are traversing in BFS way
        queue<string> words;
        words.push(beginWord);
        
        int count = 0;
        while(!words.empty()){
            count++;            
            int size = words.size();
            
            for(int i = 0; i < size; i++){
                string top = words.front();
                words.pop();
                
                // change each index char one by one, try to replace it by a-z char, and check whether it present into dictionary or not
                for(int j = 0; j < top.size(); j++){                    
                    int orgChar = top[j];

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        
                        // changing index j, with values from a - z
                        top[j] = ch;

                        if(top == endWord) return count+1;
                        if(dictionary.find(top) == dictionary.end()) continue;

                        words.push(top);
                        dictionary.erase(top);
                    }
                    top[j] = orgChar;
                }
            }
        }
        
        return 0;
    }
};
