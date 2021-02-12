
// Question) 1047. Remove All Adjacent Duplicates In String


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

string removeDuplicates(string str) {
    string res;
    res.push_back(str[0]);        
    for(int itr = 1; itr < str.size(); itr++){
        if (res.size() && res.back() == str[itr]) res.pop_back();
        else res.push_back(str[itr]);
    }            
    return res;
}
