
// Question) 77. Combinations


// Implementation


// 1st Approach
// Recursive Solution, Backtracking
class Solution {
public:
    void findCombination(vector<vector<int>> &res, vector<int> temp, int index, int n, int k){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int itr = index; itr < n; itr++){
            temp.push_back(itr+1);
            findCombination(res, temp, itr+1, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        findCombination(res, vector<int>(), 0, n, k);
        return res;
    }
};


// 2nd Approach
// Iterative Solution
class Solution {
public:   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp(k, 0);
        int itr = 0;
        while(itr > -1){
            temp[itr]++;
            if(temp[itr] > n) itr--;
            else if(itr == k-1) res.push_back(temp);
            else{                
                itr++;
                temp[itr] = temp[itr-1];
            }
        }
        return res;
    }
};
