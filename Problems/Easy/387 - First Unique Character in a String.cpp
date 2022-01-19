
// Question) 387. First Unique Character in a String


// Implementation

// 1st Approach
// Using Queue & Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<char, int> mp;
//         queue<char> q;
        
//         for(int itr = 0; itr < s.size(); itr++){
//             if(!mp[s[itr]]){
//                 mp[s[itr]] = itr+1;
//                 q.push(s[itr]);
//             }
//             else mp[s[itr]] = -1;
//         }        
        
//         while(!q.empty()){
//             if(mp[q.front()] != -1) return mp[q.front()]-1;
//             q.pop();
//         }
//         return -1;
//     }
// };


// 2nd Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<char, int> mp;        
        
//         // counting the frequency of a character present into string
//         for(int itr = 0; itr < s.size(); itr++) mp[s[itr]]++;
                
//         for(int itr = 0; itr < s.size(); itr++){
//             // at the time when we are getting char frequency as 1, we are returning the itr
//             // as itr is a index on which the character is appearing first
//             if(mp[s[itr]] == 1) return itr;
//         }
//         return -1;
//     }
// };



// 3rd Approach
// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        // taking unordered map with pair, to store the frequency of char and also the index on which that char presents
        unordered_map<char, pair<int, int>> mp;
        
        // storing the frequency of a character present into string into first, and index into second
        for(int itr = 0; itr < s.size(); itr++) {
            mp[s[itr]].first++;
            mp[s[itr]].second = itr;
        }
        
        int res = s.size();
        for(auto ch : s){
            // if the frequency if 1, it means that char is unique, and we will store the minimum index of the unique char, it means, its occuring before any other unique char
            if(mp[ch].first == 1){
                res = min(res, mp[ch].second);
            }
        }
        
        return res == s.size() ? -1 : res;
    }
};
