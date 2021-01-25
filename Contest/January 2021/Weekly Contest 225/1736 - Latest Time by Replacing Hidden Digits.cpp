
// Question) 1736. Latest Time by Replacing Hidden Digits


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

string maximumTime(string str) {
    string res = "";
    if(str[0] == '?'){
        if(str[1] > '3' && str[1] != '?'){
            res += '1';
        } 
        else res += '2';            
    }
    else res += str[0];
    
    if(str[1] == '?'){
        if(str[0] == '2') res += '3';    
        else if(str[0] != '?') res += '9';
        else res += '3';
    }
    else res += str[1];
    
    res += ':';
    
    if(str[3] == '?'){
        res += '5';            
    }
    else res += str[3];
    
    if(str[4] == '?'){
        res += '9';
    }
    else res += str[4];
    return res;
}
