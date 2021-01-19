
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
