
// Question) 557. Reverse Words in a String III


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)


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

