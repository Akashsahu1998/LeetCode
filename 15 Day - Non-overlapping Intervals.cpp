class Solution {
    public: 
    static bool comp(vector<int> &a,vector<int> &b) {
        return a[1] < b[1];
    }
    
    public:      
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {        
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);  
        int a = intervals[0][0], b = intervals[0][1], removeIntervals = 0;      
                
        for (int itr = 1; itr < intervals.size(); itr++) { 
            if((intervals[itr][1] > a) && (intervals[itr][0] < b)) removeIntervals++;
            else{
                a = intervals[itr][0];
                b = intervals[itr][1];
            }    
        } 
        return removeIntervals;
    }
};
