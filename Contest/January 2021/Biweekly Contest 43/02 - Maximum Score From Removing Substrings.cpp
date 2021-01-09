
// Question-1) 1717. Maximum Score From Removing Substrings


// Implementation

// 1st Approach in C++

int maximumGain(string s, int x, int y) {
    string a, b;
    int total = 0;
    
    for(int itr = 0; itr < s.size(); itr++){
        if(s[itr] != 'a' && s[itr] != 'b'){
            if(y >= x) {
            	int minimum = min(a.size(), b.size());
            	total += x * minimum;
            }
            else {
            	int minimum = min(a.size(), b.size());
            	total += y * minimum;
            }
            a.erase();
            b.erase();
        }
        else{
            if(y >= x){
                if(s[itr] == 'a'){
                    if(b.size() != 0){
                        total += y;
                        b.pop_back();
                    }
                    else a += s[itr];
                }
                else b += s[itr];
            }
            else{
                if(s[itr] == 'b'){
                    if(a.size() != 0){
                        total += x;
                        a.pop_back();
                    }
                    else b += s[itr];
                }
                else a += s[itr];
            }
        }
    }
    if(y >= x) {
        int minimum = min(a.size(), b.size());
        total += x * minimum;
    }
    else {
        int minimum = min(a.size(), b.size());
        total += y * minimum;
    }    
    return total;
}
