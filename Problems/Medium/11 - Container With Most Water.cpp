
// Question) 11. Container With Most Water


// Implementation

// Brute force Approach
// Giving TLE
// Time Complexity: O(N^2)
// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAns = INT_MIN;
        
        for(int itr = 0; itr < height.size()-1; itr++){
            for(int jtr = itr+1; jtr < height.size(); jtr++){
                int minVal = min(height[itr], height[jtr]);
                int total = minVal * (jtr - itr);
                maxAns = max(maxAns, total);
            }
        }
        
        return maxAns;
    }
};
