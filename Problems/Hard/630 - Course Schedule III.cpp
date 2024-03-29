
// Question) 630. Course Schedule III


// Implementation

// Using Sorting & Max Heap(Priority Queue)
// https://www.youtube.com/watch?v=ey8FxYsFAMU
// Time Complexity : O(NLogN)
// Space Complexity : O(N)

class Solution {
private:
    bool static comp(vector<int> &course1, vector<int> &course2){
        return (course1[1] != course2[1]) ? (course1[1] < course2[1]) : (course1[0] < course2[0]);
    }

public:
    int scheduleCourse(vector<vector<int>>& courses) {
    	// sort it by last day, but if last day is same then sort it by duration
        sort(courses.begin(), courses.end(), comp);
        
        // building Max Heap
        priority_queue<int> pq;
        int totalTime = 0;
        
        for(auto course : courses){
            
            // checking if we can can take the current course if, course duration is less than course last day
            if(course[0] <= course[1]){
                
                // checking current course can be complete withing the last day or not
                if(totalTime + course[0] <= course[1]){
                    pq.push(course[0]);
                    totalTime += course[0];
                }
                else{
                    
                    // checking if we can remove the max time taken course
                    if(pq.top() > course[0]){
                        totalTime -= pq.top();
                        pq.pop();
                        totalTime += course[0];
                        pq.push(course[0]);
                    }
                }
            }
        }
        return pq.size();
    }
};
