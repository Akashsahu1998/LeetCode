
// Question) 796. Rotate String


// Implementation

// Using find method
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        s += s;        
        return (s.find(goal) != string::npos);
    }
};
