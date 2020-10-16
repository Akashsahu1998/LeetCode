class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> child;
    
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
    
    public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWordToTrie(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTrie(root, 0, word);
    }
    
    TrieNode *root;
    
    void addWordToTrie(string word) {
        auto cur = root;
        
        for (auto ch : word) {
            if (!cur->child.count(ch))
                cur->child[ch] = new TrieNode();
            
            cur = cur->child[ch];
        }
        
        cur->isWord = true;
    }
    
    bool searchTrie(TrieNode* cur, int i, string word) {
        if (i == word.length())
            return cur->isWord;
        
        if (word[i] != '.') {
            if (!cur->child.count(word[i]))
                return false;

            return searchTrie(cur->child[word[i]], i + 1, word);   
        }
        
        for (auto it : cur->child) {
            if (searchTrie(it.second, i + 1, word))
                return true;               
        }
        
        return false;
    }
 
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
