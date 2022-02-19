
// Question) 2176. Count Equal and Divisible Pairs in an Array


// Implementation

// Time Complexity: O(N^2)
// Space Complexity: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0;
        for(int itr = 0; itr < nums.size()-1; itr++){
            for(int jtr = itr+1; jtr < nums.size(); jtr++){
                if((nums[itr] == nums[jtr]) && ((itr * jtr) % k == 0)) cnt++;
            }
        }
        return cnt;
    }
};
