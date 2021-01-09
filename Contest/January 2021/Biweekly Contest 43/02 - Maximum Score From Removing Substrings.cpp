
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


// 2nd Approach in Java

public int maximumGain(String s, int x, int y) {
    String a = "", b = "";
    int total = 0;
    
    for(int itr = 0; itr < s.length(); itr++){
        if(s.charAt(itr) != 'a' && s.charAt(itr) != 'b'){
            if(y >= x) {
            	int min = Math.min(a.length(), b.length());
            	total += x * min;
            }
            else {
            	int min = Math.min(a.length(), b.length());
            	total += y * min;
            }
            a = a.substring(0, 0);
            b = b.substring(0, 0);                
        }
        else{
            if(y >= x){
                if(s.charAt(itr) == 'a'){
                    if(b.length() != 0){
                        total += y;
                        b = b.substring(0, b.length() - 1);
                    }
                    else a += s.charAt(itr);
                }
                else b += s.charAt(itr);
            }
            else{
                if(s.charAt(itr) == 'b'){
                    if(a.length() != 0){
                        total += x;
                        a = a.substring(0, a.length() - 1);
                    }
                    else b += s.charAt(itr);
                }
                else a += s.charAt(itr);
            }
        }
    }
    if(y >= x) {
    	int min = Math.min(a.length(), b.length());
    	total += x * min;
    }
    else {
    	int min = Math.min(a.length(), b.length());
    	total += y * min;
    }
    return total;
}


