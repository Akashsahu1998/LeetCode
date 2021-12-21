
// Question) 1306. Jump Game III


// Implementation

// Recursive Approach
// Time Complexity = O(N), Space Complexity = O(N) (we are considering the recursion stack)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start] == -1) return false;
        if(!arr[start]) return true;
        int prev = arr[start];
        arr[start] = -1;
        return canReach(arr, start + prev) || canReach(arr, start - prev);
    }
};
