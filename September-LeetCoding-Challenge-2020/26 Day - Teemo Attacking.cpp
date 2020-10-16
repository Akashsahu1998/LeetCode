
// Time Complexity = O(N)

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int a = -1, res = 0;
        for(auto t : timeSeries) {
            if(t <= a)
            	res -= a - t + 1;            
            a = t + duration - 1;
            res += duration;
        }
        return res;
    }
};
