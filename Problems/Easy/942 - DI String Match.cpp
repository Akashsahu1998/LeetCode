
// Question) 942. DI String Match


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)


vector<int> diStringMatch(string S) {
    vector<int> res;
    int ktr = S.size(), jtr = 0;
    
    if(S[0] == 'I'){
        res.push_back(jtr++);            
    }
    if(S[0] == 'D'){
        res.push_back(ktr--);            
    }
    
    for(int itr = 1; itr < S.size(); itr++){
        if(S[itr] == 'I') res.push_back(jtr++);
        if(S[itr] == 'D') res.push_back(ktr--);
    }
    
    if(S[S.size()-1] == 'I'){
        res.push_back(jtr++);            
    }
    if(S[S.size()-1] == 'D'){
        res.push_back(ktr--);            
    }
    
    return res;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int[] diStringMatch(String S) {
    int[] res = new int[S.length()+1];
    int ktr = S.length(), jtr = 0, index = 0;
    
    if(S.charAt(0) == 'I'){
        res[index++] = jtr++;          
    }
    if(S.charAt(0) == 'D'){
        res[index++] = ktr--;            
    }
    
    for(int itr = 1; itr < S.length(); itr++){
        if(S.charAt(itr) == 'I') res[index++] = jtr++;
        if(S.charAt(itr) == 'D') res[index++] = ktr--;
    }
    
    if(S.charAt(S.length()-1) == 'I'){
        res[index++] = jtr++;
    }
    if(S.charAt(S.length()-1) == 'D'){
        res[index++] = ktr--;            
    }
    
    return res;
}
