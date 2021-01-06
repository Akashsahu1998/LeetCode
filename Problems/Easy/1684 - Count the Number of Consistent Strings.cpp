
// Question) 1684. Count the Number of Consistent Strings


// Implementation

// 1st Approach in C++
int countConsistentStrings(string allowed, vector<string>& words) {
    int count = 0;
    for(int itr = 0; itr < words.size(); itr++){
        string str = words[itr];
        
        for(int jtr = 0; jtr < allowed.size(); jtr++){
            for(int ktr = 0; ktr < str.size(); ktr++){
                if(str[ktr] == allowed[jtr]) str[ktr] = '.';
            }
        }
        
        int flag = 0;
        for(int jtr = 0; jtr < str.size(); jtr++){
            if(str[jtr] != '.'){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0) count++;
    }
    return count;
}


// 2nd Approach in C++

int countConsistentStrings(string allowed, vector<string>& words) {
    int count = 0;
    int arr[26] = {0};
    for(int itr = 0; itr < allowed.size(); itr++){
        arr[allowed[itr]-'a']++;    
    }       
    
    for(int itr = 0; itr < words.size(); itr++){
        string str = words[itr];            
        int flag = 0;
        for(int ktr = 0; ktr < str.size(); ktr++){
            if(arr[str[ktr]-'a'] == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0) count++;
    }
    return count;
}
