
// Question) 159. Longest Substring with At Most Two Distinct Characters


// Implementation

// 1st Approach
// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if (n < 3) return n;

        // sliding window left and right pointers
        int left = 0, right = 0;
        
        // hashmap character -> its rightmost position
        map<char, int> mp;

        int maxLenAns = 2, freq = INT_MAX;
        char ch = '';

        while (right < n) {
            // when the sliding window contains less than 3 characters
            mp[s[right]] = right;
            
            if(freq > mp[s[right]]){
                ch = s[right];
                freq = right;
            }
            
            right++;
            
            

            // slidewindow contains 3 characters
            while (mp.size() == 3) {
                char ch = s[left];
                if(mp[ch] <= left){
                    mp.erase(ch);
                }
                left++;
            }
            maxLenAns = max(maxLenAns, right - left);
        }
        return maxLenAns;
    }
};
