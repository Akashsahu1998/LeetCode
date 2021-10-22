
// Question) 316. Remove Duplicate Letters


// Implementation

// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> frequency;
        unordered_map<char, bool> visited;
        string res;
        for(auto ch : s) frequency[ch]++;
        for(auto ch : s){
            frequency[ch]--;
            if(visited[ch]) continue;
            while(!res.empty() && res.back() > ch && frequency[res.back()] > 0){
                visited[res.back()] = false;
                res.pop_back();
            }
            visited[ch] = true;
            res += ch;
        }
        return res;
    }
};
