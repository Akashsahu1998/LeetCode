
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
