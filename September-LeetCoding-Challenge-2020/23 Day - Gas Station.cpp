
// Time Complexity = O(N)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, end = cost.size()-1;
        int remain = gas[end] - cost[end];
        while (start < end) {
            if (remain < 0){
                end--;
                remain += gas[end] - cost[end];
           }
            else {
                remain += gas[start] - cost[start];
                start++;
           }
        }
        if(remain >= 0) return end;
        else return -1;        
    }
};
