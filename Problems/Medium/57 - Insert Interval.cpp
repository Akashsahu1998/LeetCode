
// Question) 57. Insert Interval


// Implementation

// Using Sorting
// Time Complexity: O(N)
// Space Complexity: O(1), not considering the res vector of vector, bcz that's a part of o/p

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resultInterval;        
        int itr = 0;
        
        // Adding(Small result) into result, if 2nd index is less than first index of new interval  
        while(itr < intervals.size() && intervals[itr][1] < newInterval[0]) {
            resultInterval.push_back(intervals[itr]);
            itr++;
        }
        
        int var1 = newInterval[0];
        int var2 = newInterval[1];
        
        // finding minimum value for 1st index
        if(itr < intervals.size()) var1 = min(var1, intervals[itr][0]);           
        
        // finding the maximum value for 2nd index
        while(itr < intervals.size() && newInterval[1] >= intervals[itr][0]) {
            var2 = max(var2, intervals[itr][1]);            
            itr++;
        }
        
        //Add the minimum and maximum value
        resultInterval.push_back({var1, var2});
    
        //adding the last remaining result
        while(itr < intervals.size()) {
            resultInterval.push_back(intervals[itr]);
            itr++;            
        }
        
        return resultInterval;
    }
};
