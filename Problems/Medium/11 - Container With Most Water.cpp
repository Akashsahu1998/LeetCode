
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


// Efficient Approach
// Using Two Pointer's Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // taking maxAns to store the ans
        int maxAns = INT_MIN;
        
        // taking two pointers
        int start = 0, end = height.size()-1;
        
        // run untill and unless start become greater than or equal to end
        while(start < end){
            
            // taking the minimum of both start and end index value
            int minVal = min(height[start], height[end]);
            
            // calculating the distance b/w the start & end & multiplying it with minVal
            int total = minVal * (end - start);
            
            // storing the max ans 
            maxAns = max(maxAns, total);
            
            // if end value is greater than start, just increment start by 1
            if(height[start] < height[end]){
                start++;
            }
            else{   // otherwise decrement end by 1
                end--;
            }
        }
        
        return maxAns;
    }
};
