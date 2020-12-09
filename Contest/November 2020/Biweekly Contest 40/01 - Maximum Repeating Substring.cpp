
// Q1.) 1668. Maximum Repeating Substring

// Implementation
// Time Complexity = O(M * N)


class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string newWord = word;
        while(sequence.find(newWord) != string::npos)
        {
            res++;
            newWord += word;
        }
        return res;
    }
};


