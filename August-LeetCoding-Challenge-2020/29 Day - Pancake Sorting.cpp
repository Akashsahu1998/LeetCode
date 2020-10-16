class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> array;
        for(int itr = 0; itr < A.size(); itr++){
           auto maxPos = max_element(A.begin(), A.end() - itr);
           array.push_back(maxPos - A.begin() + 1);  
           array.push_back(A.size() - itr);
           reverse(A.begin(), maxPos + 1);
           reverse(A.begin(), A.end() - itr);
        }
        return array;        
    }
};
