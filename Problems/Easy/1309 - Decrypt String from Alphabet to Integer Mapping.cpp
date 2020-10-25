
// Question) 1309. Decrypt String from Alphabet to Integer Mapping

// Implementation

class Solution {
public:
    string freqAlphabets(string s) {        
        
        string str = "";
        
        for(int itr = s.size()-1; itr >= 0; ){
            if(s[itr] == '#'){
                int a = s[itr - 2];
                a = a - 48;
                
                int b = s[itr - 1];
                b = b - 48;
                
                a = a * 10 + b;
                
                str = str + char(97 + a - 1);
                itr = itr - 3;
            }
            else{
                int a = s[itr];
                a = a - 48;
                
                str = str + char(97 + a - 1);
                itr--;
            }
        }        
        
        reverse(str.begin(), str.end()); 
        return str;
    }
};
