// Question) 657. Robot Return to Origin


// Implementation

// 1st Approach in C++ Using Map

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> mp;
        for(int itr = 0; itr < moves.size(); itr++){
            mp[moves[itr]]++;
        }
        
        if(mp['U'] != 0 && mp['D'] != 0 && mp['L'] != 0 && mp['R'] != 0){
            if((mp['U'] == mp['D']) && (mp['R'] == mp['L']))
                return true;    
            else if((mp['U'] == mp['D']) && (mp['R'] != mp['L'])){
                return false;                
            }
            else if((mp['L'] == mp['R']) && (mp['U'] != mp['D'])){
                return false;                
            }            
        }
        
        if((mp['U'] == mp['D']) && (mp['R'] == mp['L']))
                return true;    
        else
            return false;
                
    }
};
