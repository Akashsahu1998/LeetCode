
// Question) 84. Largest Rectangle in Histogram


// Implementation

// Naive Approach
// Getting TLE
// Time Complexity = O(N^2), Space Complexity = O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = -1;
        for(int itr = 0; itr < heights.size(); itr++){
            
            int left = 0;
            // finding on left if any element is less than the current element
            // if there is no element less, then left will be having 0
            for(int jtr = itr-1; jtr >= 0; jtr--){
                if(heights[jtr] < heights[itr]){
                    left = jtr+1;
                    break;
                }
            }
            
            int right = heights.size()-1;
            // finding on right if any element is less than the current element
            // if there is no element less, then right will be having n-1
            for(int jtr = itr+1; jtr < heights.size(); jtr++){
                if(heights[jtr] < heights[itr]){
                    right = jtr-1;
                    break;
                }
            }
            
            int sum = (right - left + 1) * heights[itr];
            ans = max(ans, sum);
        }
        return ans;
    }
};
