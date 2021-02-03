
// Question) 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence


// Implementation

// 1st Approach in C++
// Time Complexity = O(searchWord.length*Number of words), Space Complexity = O(Number of words)

int isPrefixOfWord(string sentence, string searchWord) {
    string word;
    stringstream ss(sentence); 
    int count = 0;
    while(ss >> word){
        count++;
        if(word[0] == searchWord[0]){
            bool flag = true;
            for(int jtr = 1, ktr = 1; jtr < searchWord.size(); jtr++, ktr++){
                if(searchWord[ktr] != word[jtr]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) return (count);
        }            
    }
    return -1;
}

// 2nd Approach in C++
// Time Complexity = O(searchWord.length*Number of words), Space Complexity = O(Number of words)

int isPrefixOfWord(string sentence, string searchWord) {
    string word;
    stringstream ss(sentence); 
    int count = 0;
    while(ss >> word){
        count++;
        if(word.find(searchWord) == 0 ) return count;      
    }
    return -1;
}
