// 1st Method
// Time Complexity = O(n), Space Complexity = O(k)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);        
        res[0] = 1, res[rowIndex] = 1;
        for(int itr = 1; itr < res.size() - 1; itr++){
            res[itr] = (long) res[itr - 1] * (rowIndex - (itr - 1)) / itr;
        }        
        return res;
    }
};


// 2nd Method
// Time Complexity = O(n), Space Complexity = O(k)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);        
        res[0] = 1;
        int itr, newItr;
        for(itr = 1; itr <= res.size() / 2; itr++){
            res[itr] = (long) res[itr - 1] * (rowIndex - (itr - 1)) / itr;
        }        
        newItr = itr;
        if(rowIndex % 2 == 0) itr -= 2;
        else itr -= 3;
        for( ; newItr < res.size(); newItr++){
            res[newItr] = res[itr];
            itr -= 1;
        }
        return res;
    }
};

            

