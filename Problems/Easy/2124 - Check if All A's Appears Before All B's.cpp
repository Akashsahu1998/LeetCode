
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


// Just simply checking the [index-1] value
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    bool checkString(string str) {       
        for(int itr = 1; itr < str.size(); itr++){
            if(str[itr] == 'a' && str[itr-1] == 'b') return false;
        }
        return true;
    }
};
