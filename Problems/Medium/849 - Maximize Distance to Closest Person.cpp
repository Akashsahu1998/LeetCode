
// Que) 849. Maximize Distance to Closest Person


// Implementation

// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, lastOccurenceOfOne = -1, size = seats.size();
        
        for(int i = 0; i < size; i++){
            if(seats[i]){
                res = (lastOccurenceOfOne == -1) ? i : max(res, (i-lastOccurenceOfOne)/2);
                lastOccurenceOfOne = i;
            }
        }
        res = max(res, size - lastOccurenceOfOne - 1);
        return res;
    }
};
