
// Question) 2124. Check if All A's Appears Before All B's


// Implementation

// Using flag variable
// Time Complexity = O(N), Space Complexity = O(N)

class Solution {
public:
    bool checkString(string str) {
        bool flag = false;
        for(auto s : str){
            if(s == 'b') flag = true;
            if(s == 'a' && flag == true) return false;
        }
        return true;
    }
};
