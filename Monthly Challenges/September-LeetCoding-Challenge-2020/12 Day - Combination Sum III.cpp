class Solution {
public:
    vector<vector<int>> ans;    
    void GetPermutation(vector<int>& subset, int curSum, int tarSum, int setLen, int left) {
		//We return when we've explored max numbers allowed to form the sum.
        if(subset.size() == setLen) {
			//We get one possible answer if current sum becomes equal to target sum.
            if(curSum == tarSum)
                ans.push_back(subset);
            return;
        }

		//We explore all possibilities from left till 9. For first call left = 1.
        for(int i = left; i <= 9; ++i) {
            subset.push_back(i);
            curSum += i;
			//We need digits greater than i, that's why we pass i+1 into next recursion.
            GetPermutation(subset, curSum, tarSum, setLen, i+1);
			//We reset to state which was before we went into recursion.
            curSum -= i;
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
		//Initial call.
        GetPermutation(subset, 0, n, k, 1);
        return ans;
    }
};
