
// Question) 1897. Redistribute Characters to Make All Strings Equal


// Implementation

// 1st Approach in C++

bool makeEqual(vector<string>& words) {        
    unordered_map<char, int> ump;
    for(int itr = 0; itr < words.size(); itr++){
        string str = words[itr];
        int jtr = 0;
        while(str[jtr]) ump[str[jtr++]]++;
    }
    for(auto f: ump){
        if(f.second % (words.size()) != 0) return false;
    }
    return true;
}

