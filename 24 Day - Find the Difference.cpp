
// Time Complexity = O(n)

class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset <char> st1(begin(s), end(s));
        multiset <char> st2(begin(t), end(t));
        char ch;

        multiset <char> :: iterator itr1 = st1.begin(); 
        multiset <char> :: iterator itr2 = st2.begin();

        int flag = 0; 
        for ( ; itr1 != st1.end(); itr1++, itr2++) { 
            if(*itr1 != *itr2){        	
                ch = *itr2;
                flag = 1;
                break;
            }  
        }
    
        if(flag == 0) ch = *itr2;   		

        return ch;
    }
};
