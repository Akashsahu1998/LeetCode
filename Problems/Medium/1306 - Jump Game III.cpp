
// Question) 1306. Jump Game III


// Implementation

// DFS
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


// BFS
// Using Queue
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:    
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int itr = 0; itr < size; itr++){
                int index = q.front();
                q.pop();
                
                // Checking Left
                if(index - arr[index] >= 0){
                    if(arr[index - arr[index]] == 0) return true;
                    else if(arr[index - arr[index]] > 0) q.push(index - arr[index]);
                }
                
                // Checking Right
                if(index + arr[index] < arr.size()){
                    if(arr[index + arr[index]] == 0) return true;
                    else if(arr[index + arr[index]] > 0) q.push(index + arr[index]);
                }
                
                arr[index] = -1;
            }
        }
        return false;
    }
};
