
// Question) 2134. Minimum Swaps to Group All 1's Together II


// Implementation

// using sliding window technique
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOne = 0, n = nums.size();
        
        // count the total number of 1's present into array
        for(int itr = 0; itr < n; itr++){
            if(nums[itr]) countOne++;
        }
        
        // if no one is present then simply return 0
        if(countOne == 0) return 0;
        
        // taking the window size of the total 1's count
        int windowSize = countOne;
        int currCountOne = 0;        
        
        // counting the number of 1's present into the starting window size from 0
        for(int itr = 0; itr < countOne; itr++){
            if(nums[itr]) currCountOne++;
        }
        
        // putting into the res, bcz res will hold the maximum number of 1's present into the current window size
        int res = currCountOne;
        for(int itr = 1; itr < n; itr++){
            
            // if leading element is 1 then decrement it by 1, bcz now it's not in a current window
            if(nums[itr-1]) currCountOne--;
            
            // if trailing element is 1 then increment it by 1, bcz now it's in a current window
            if(nums[(itr + windowSize - 1) % n]) currCountOne++;
            
            // storing the maximum count of 1's in a current window
            res = max(res, currCountOne);
        }        
        
        // return total number of 1's in a array - maximum count of 1's in a current window
        return windowSize - res;
    }
};
