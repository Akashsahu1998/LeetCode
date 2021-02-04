
// Question) 1002. Find Common Characters


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(N)

vector<string> commonChars(vector<string>& A) {
    vector<int> check1(26, 0);
    vector<int> check2(26, 0);
    vector<string> result;
    
    for(char ch : A[0]){
        check1[ch-'a']++;
    }
    
    for(int itr = 1; itr < A.size(); itr++){
        for(char ch : A[itr]){
            check2[ch-'a']++;
        }
        
        for(int jtr = 0; jtr < 26; jtr++){
            check1[jtr] = min(check1[jtr], check2[jtr]); 
            check2[jtr] = 0;
        }
    }
           
    for(int itr = 0; itr < 26; itr++){
        if(check1[itr]){
            int value = check1[itr];
            while(value--){
                char ch = itr + 'a';
                string str;
                str = ch;
                result.emplace_back(str);                                
            }                
        }
    }
    return result;
}


