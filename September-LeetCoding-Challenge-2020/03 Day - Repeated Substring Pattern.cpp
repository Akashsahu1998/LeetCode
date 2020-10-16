class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.length();
        if (size % 4==0 && s.substr(0, s.length() / 2) == s.substr(s.length() / 2)) return true;
        for (int itr = 1; itr <= size / 2; itr++) {
            if (size % itr == 0 && s.substr(s.length() / size * itr) + s.substr(0, s.length() / size * itr) == s) return true;
        }   
        return false;
    }
};
