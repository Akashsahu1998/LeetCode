
// Question) 1450. Number of Students Doing Homework at a Given Time

// Implementation

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int countResult = 0;
        for(int itr = 0; itr < startTime.size(); itr++){
            if(startTime[itr] <= queryTime && endTime[itr] >= queryTime) countResult++;
        }
        return countResult;
    }
};
