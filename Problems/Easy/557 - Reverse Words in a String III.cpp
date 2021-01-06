
// Question) 557. Reverse Words in a String III


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(N)

string reverseWords(string s) {
    string str = "";
    
    for(int jtr = 0, itr = 0; itr < s.size(); itr++){
        if(s[itr] == ' ' || itr == s.size()-1){      
            if(itr == s.size()-1) itr++;
            for(int ktr = itr-1 ; ktr >= jtr; ktr--){
                str += s[ktr];
            }
            jtr = itr+1;
            if(itr != s.size()) str += ' ';
        }            
    }
    return str;
}


// 2nd Approach in Java
// Time Complexity = O(N^2), Space Complexity = O(N)

public String reverseWords(String s) {
    String str = "";
    
    for(int jtr = 0, itr = 0; itr < s.length(); itr++){
        if(s.charAt(itr) == ' ' || itr == s.length()-1){      
            if(itr == s.length()-1) itr++;
            for(int ktr = itr-1 ; ktr >= jtr; ktr--){
                str += s.charAt(ktr);
            }
            jtr = itr+1;
            if(itr != s.length()) str += ' ';
        }            
    }
    return str;
}


