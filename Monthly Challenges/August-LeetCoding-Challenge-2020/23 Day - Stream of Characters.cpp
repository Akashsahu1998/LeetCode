
class Trie {
	unordered_map<char, Trie *> cMap;
	bool wordEnd;
    
    public:    
	Trie() {
		wordEnd = false;
	}

	void insertWord(string word) {
		if(word.length() == 0) return;			

		Trie *temp = this;
		for(auto ch : word) {
			if(temp -> cMap.find(ch) != temp -> cMap.end()) temp = temp -> cMap[ch];
            else {
				temp -> cMap[ch] = new Trie();
				temp = temp -> cMap[ch];
			}
		}

		temp -> wordEnd = true;
	}

	bool searchWord(string word) {
		if(word.length() == 0)
			return false;

		Trie *temp = this;
		for(auto ch : word) {
			if(temp -> cMap.find(ch) == temp -> cMap.end()) return false;				
			temp = temp -> cMap[ch];
			if(temp -> wordEnd) return true;				
		}
		return temp -> wordEnd;
	}
};

class StreamChecker {
    Trie trie;
	string tempStr = "";
	int wordLength = 0;
    
    public:
    StreamChecker(vector<string>& words) {
        for(auto word : words) {
			reverse(word.begin(), word.end());
			wordLength = max(wordLength, (int)word.length());
			trie.insertWord(word);
		}
    }
    
    bool query(char letter) {
        tempStr = letter + tempStr;
		if(tempStr.length() > wordLength) tempStr.pop_back();
		return trie.searchWord(tempStr);
    }
};



/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
