
// Question) 42. Trapping Rain Water


// Implementation

// Using stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, left = 0, n = height.size();
        stack<int> right; 
        right.push(n-1);
        
        for(int itr = n-2; itr > 0; itr--){
            if(height[itr] > height[right.top()]) right.push(itr);
        }
        
        for(int itr = 1; itr < n-1; itr++){
            if(height[left] > height[itr] && height[itr] < height[right.top()]){
                ans += min(height[left], height[right.top()]) - height[itr];
            }
            else if(height[left] < height[itr]) left = itr;
            
            if(itr == right.top()) right.pop();
        }
        return ans;
    }
};


// Using two pointer approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1, leftMax = -1, rightMax = -1;
        
        while(left < right){
            if(height[right] >= height[left]){
                if(height[left] >= leftMax) leftMax = height[left];
                else ans += leftMax - height[left];
                left++;
            }
            else{
                if(height[right] >= rightMax) rightMax = height[right];
                else ans += rightMax - height[right];
                right--;
            }
        }
        
        return ans;
    }
};


/*

**1) Approach O(N^2) Time, Space O(1)**
1) iterate over the array and find the max from left and max from right as well
2) calculate the ans based on this

**2) Approach O(N) Time, Space (N)**
1) store the max element from left
2) store the max element from right
3) just iterate over the array and calculate the ans

**3) Approach O(N) Time, Space (1)**
1) take var left, right, start left from 0 and right from end
2) take two more var, leftMax in which we will store the left max value from left, and in rightMax we will store the max value from right side.
3) check the left and right element, and for these update the respective values and calculate the ans

*/
