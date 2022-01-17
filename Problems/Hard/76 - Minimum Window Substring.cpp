
// Question) 76. Minimum Window Substring


// Implementation

// https://www.youtube.com/watch?v=e1HlptlipB0
// Using unordered_map & Two Pointers/Window Sliding Technique
// Time Complexity = O(N), Space Complexity = O(1), space O(1), bcz we will going to store till only 256 characters in the map, and that's a constant value
class Solution {
public:
    string minWindow(string s, string p) {
        if(p.size() > s.size()) return "";
        
        unordered_map<char, int> mpPattern;
        for(int itr = 0; itr < p.size(); itr++){
            mpPattern[p[itr]]++;
        }
        
        unordered_map<char, int> mpStr;
        int itr=0, jtr=0, startingIndex = -1, minLen = INT_MAX, count=0;
        
        while(itr < s.size()){
            
            // acquiring elements
            while(itr < s.size() && count < p.size()){
                
                // increasing the frequency of s[itr]
                mpStr[s[itr]]++;
                
                // if frequency of s[itr] is less than the frequency of pattern then increment count, bcz that is of our use
                if(mpStr[s[itr]] <= mpPattern[s[itr]]){
                    count++;
                }
                
                itr++;
            }
            
            // collecting answers and releasing elements
            while(jtr < itr && count == p.size()){
                
                // if current length of windows is minimum length then update the ans
                if(minLen > itr-jtr){
                    minLen = itr-jtr;
                    startingIndex = jtr;
                }
                
                // decreasing the frequency of s[jtr]
                mpStr[s[jtr]]--;
                
                // if frequency of s[jtr] is less than the frequency of pattern then decrement count, bcz the element which was our use, got removed, so decrement count
                if(mpStr[s[jtr]] < mpPattern[s[jtr]]){
                    count--;
                }
                
                jtr++;
            }
        }
        
        if(startingIndex == -1) return "";
        return s.substr(startingIndex, minLen);
    }
};
