
// Question) 832. Flipping an Image

// Implementation

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& vec) {
        for(auto& row : vec){
            reverse(row.begin(), row.end());
        }
        
        for(int itr = 0; itr < vec.size(); itr++){            
            for(int jtr = vec[itr].size()-1; jtr > -1; jtr--){
                if(vec[itr][jtr]) vec[itr][jtr] = 0;
                else vec[itr][jtr] = 1;
            }
        }
        
        return vec;
    }
};
