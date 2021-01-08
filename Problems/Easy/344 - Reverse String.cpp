
// Question) 344. Reverse String


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

void reverseString(vector<char>& s) {
    int itr = 0, jtr = s.size()-1;
    while(itr <= jtr){
        char ch = s[itr];
        s[itr] = s[jtr];
        s[jtr] = ch;
        itr++; jtr--;
    }
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public void reverseString(char[] s) {
    int itr = 0, jtr = s.length-1;
    while(itr <= jtr){
        char ch = s[itr];
        s[itr] = s[jtr];
        s[jtr] = ch;
        itr++; jtr--;
    }        
}
