
// Question) 1784. Check if Binary String Has at Most One Segment of Ones


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

bool checkOnesSegment(string s) {
    if(s.size() == 1 && s[0] == '1') return true;
    
    for(int itr = 1; itr < s.size(); itr++){
        if(s[itr-1] == '0' && s[itr] == '1') return false;
    }        
    return true;
}
