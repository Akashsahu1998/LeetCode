
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


// Efficient Approach
// Traversing 3 times
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftArr(n), rightArr(n);
        stack<int> st;
        
        // finding element on left which is lesser than the current element
        for(int itr = 0; itr < n; itr++){
            while(!st.empty() && heights[st.top()] >= heights[itr]){
                st.pop();
            }
            
            // if stack is empty then put 0
            if(st.empty()){
                leftArr[itr] = 0;
            }
            else{
                leftArr[itr] = st.top() + 1;
            }
            
            st.push(itr);
        }
        
        // clear stack, to create rightArr
        while(!st.empty()){
            st.pop();
        }
        
        // finding element on right which is lesser than the current element
        for(int itr = n-1; itr >= 0; itr--){
            while(!st.empty() && heights[st.top()] >= heights[itr]){
                st.pop();
            }
            
            // if stack is empty then put n-1
            if(st.empty()){
                rightArr[itr] = n-1;
            }
            else{
                rightArr[itr] = st.top() - 1;
            }
            
            st.push(itr);
        }
        
        // calculating the max rectangle by using left & right less current value
        int ans = -1;
        for(int itr = 0; itr < n; itr++){
            int sum = (rightArr[itr] - leftArr[itr] + 1) * heights[itr];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
