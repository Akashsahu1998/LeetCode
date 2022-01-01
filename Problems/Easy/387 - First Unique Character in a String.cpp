
// Question) 387. First Unique Character in a String


// Implementation

// Using Queue & Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<char> q;
        
        for(int itr = 0; itr < s.size(); itr++){
            if(!mp[s[itr]]){
                mp[s[itr]] = itr+1;
                q.push(s[itr]);
            }
            else mp[s[itr]] = -1;
        }        
        
        while(!q.empty()){
            if(mp[q.front()] != -1) return mp[q.front()]-1;
            q.pop();
        }
        return -1;
    }
};


// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;        
        
        // counting the frequency of a character present into string
        for(int itr = 0; itr < s.size(); itr++) mp[s[itr]]++;
                
        for(int itr = 0; itr < s.size(); itr++){
            // at the time when we are getting char frequency as 1, we are returning the itr
            // as itr is a index on which the character is appearing first
            if(mp[s[itr]] == 1) return itr;
        }
        return -1;
    }
};
