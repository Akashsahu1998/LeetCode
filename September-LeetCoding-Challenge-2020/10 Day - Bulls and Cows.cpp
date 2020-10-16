class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp;
        int num1 = 0, num2 = 0;
        for(int itr = 0; itr < secret.size(); itr++)
            mp[secret[itr]] = 0;   
        for(int itr = 0; itr < secret.size(); itr++) {
            if(secret[itr] != guess[itr]) mp[secret[itr]]++;            
        }
        for(int itr = 0; itr < guess.size(); itr++) {
            if(secret[itr] == guess[itr]) num1++;                
            else {
                if(mp[guess[itr]] >= 1) {
                    num2++;
                    mp[guess[itr]]--;
                }
            }
        }
        string secretNum = to_string(num1);
        secretNum += 'A';
        secretNum += to_string(num2);
        secretNum += 'B';
        return secretNum;
    }
};
