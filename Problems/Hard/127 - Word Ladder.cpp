
// Question) 127. Word Ladder


// Implementation

// BFS Approach
// Using Queue & Unordered Set
// Time Complexity = O(N * M * 26), Where N is the length of the wordList, M is the size of the word present into the wordList, and 26 means, from a to z we are running the loop
// Space Complexity = O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        
        for(auto word : wordList){
            st.insert(word);
        }
        
        if(st.find(endWord) == st.end()) return 0;
        
        int count = 0;
        queue<string> word;
        word.push(beginWord);
        
        while(!word.empty()){
            count++;
            int size = word.size();
            
            for(int i = 0; i < size; i++){
                string top = word.front();
                word.pop();
                
                for(int j = 0; j < top.size(); j++){
                    char ch = top[j];
                    
                    for(char c = 'a'; c <= 'z'; c++){
                        top[j] = c;
                        
                        if(top == endWord) return count+1;
                        if(st.find(top) == st.end()) continue;
                        
                        st.erase(top);
                        word.push(top);
                    }
                    top[j] = ch;
                }
            }
        }
        
        return 0;
    }
};
