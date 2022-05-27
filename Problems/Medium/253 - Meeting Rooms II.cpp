
// Question) 253. Meeting Rooms II


// Implementation

// Using Sorting & Two Pointers Technique
// Time Complexity : O(NlogN)
// Space Complexity : O(N)
class Solution {    
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<int> startTime;
        vector<int> endTime;
        
        for(int i = 0; i < intervals.size(); i++){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        
        int curRequiredMetingRoomCount = 0, maxRequiredMetingRoomCount = 0;
        int i = 0, j = 0;
        while(i < startTime.size()){
            if(startTime[i] < endTime[j]){
                curRequiredMetingRoomCount++;
                i++;
            }
            else {
                curRequiredMetingRoomCount--;
                j++;
            }
            
            maxRequiredMetingRoomCount = max(maxRequiredMetingRoomCount, curRequiredMetingRoomCount);
        }
        
        return maxRequiredMetingRoomCount;
    }
};
