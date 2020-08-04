class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        string myStr;
        transform(s.begin(), s.end(), s.begin(), :: tolower); 
        for(int i = 0; i < s.length(); i++){
            if( (s[i] >= 97 && s[i] <= 122) || ((s[i] >= 48 && s[i] <= 57)) ){
                myStr += s[i];   
            }
        }      
        int start = 0, end = myStr.length() - 1;
        while(start < end){
            if(myStr[start] != myStr[end]){
                ans = false; break;
            }
            ans = true;
            start++; end--;
        }
        return ans;
    }
};
