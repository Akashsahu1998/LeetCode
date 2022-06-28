
// Question) 759. Employee Free Time


// Implementation

// Using Unordered Map
// Time Complexity : O(NLogN)
// Time Complexity : O(N)

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        // taking map bcz it will store in ascending order
        map<int, int> mp;
        vector<Interval> res;
        
        // if start interval is there then do ++, for end do --;
        for(auto list : schedule){
            for(auto subList : list){
                mp[subList.start]++;
                mp[subList.end]--;
            }
        }
        
        int time = 0;
        for(auto keyValue : mp){
            time += keyValue.second;
            
             // if time is reaching to 0, it means we got one starting interval which is common for all employees, but still we are pending with end interval so we will make it 0 for now.
            if(time == 0) res.push_back(Interval(keyValue.first, 0));
            
            // if our time is having value, and res is not empty, and res last element end is 0, then
            // it means we are having one interval which is having start interval but not having end interval, so
            // we will push the first value as a interval
            if(time && !res.empty() && res.back().end == 0){
                res.back().end = keyValue.first;
            }
        }
        
        // res last element is not having end interval, then pop it, bcz that's not a valid interval, bcz its going to infinite, but we want finite interval
        if(res.back().end == 0){
            res.pop_back();
        }
        
        return res;
    }
};

// Algo Steps :
// 1) taking map bcz it will store in ascending order
// 2) if start interval is there then do ++, for end do --
// 3) iterate over the map, and add time, and check if time is 0, then we got the first start interval
// 4) check to get the last interval

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
