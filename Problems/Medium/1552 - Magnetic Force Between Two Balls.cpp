
// Question) 1552. Magnetic Force Between Two Balls.cpp


// Implementation

// Using Binary Search
// Time Complexity = O(NLogN), Space Complexity = O(1)
class Solution {
public:
    bool isPossible(vector<int>& position, int mid, int m) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= mid) {
                ans++;
                cur = position[i];
            }
            if(ans >= m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0, high = position.back() - position.front();
        int ans = -1;
        while(low <= high){
            int mid = high - (high - low)/2;
            if(isPossible(position, mid, m)){
                low = mid+1;
                ans = mid;
            }
            else high = mid-1;
        }
        return ans;
    }
};
