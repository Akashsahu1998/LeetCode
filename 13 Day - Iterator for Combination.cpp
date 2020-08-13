
class CombinationIterator {
public:
    int last, combinationLengthLen;
    string str;
    vector<int> vect1, vect2;
    
    CombinationIterator(string characters, int combinationLength) {
        combinationLengthLen = combinationLength;        
        vect2.resize(combinationLengthLen, 0);
        last = -1;
        str = characters;
        for(int itr1 = 0; itr1 < combinationLengthLen; itr1++) vect1.emplace_back(itr1);        
        for(int itr1 = combinationLengthLen - 1, itr2 = characters.size() - 1; itr1 >= 0; itr1--, itr2--) vect2[itr1] = itr2;
        if(characters.size() == combinationLengthLen) last = 0;
    }
    
    string next() {
        string result;
        for(int itr1 = 0; itr1 < vect1.size(); itr1++) result += str[vect1[itr1]];
        int itr1 = vect1.size() - 1;
        bool flag = false;
        for( ; itr1 > last; itr1--)
        {
            if(vect1[itr1] < vect2[itr1])
            {
                vect1[itr1]++;
                flag = true;
                if((itr1 == last + 1) && (vect1[itr1] == vect2[itr1])) last = itr1;
                break;
            }
        }
        if(!flag) last = combinationLengthLen-1;        
        for(int itr2 = itr1 + 1; itr2 < vect1.size(); itr2++) vect1[itr2] = vect1[itr2 - 1] + 1;        
        return result;
    }
    
    bool hasNext() {
        if(last + 1 == combinationLengthLen) return false;            
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
