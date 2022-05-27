
// Question) 857. Minimum Cost to Hire K Workers


// Implementation

// ***** Idea *****
// So to minimize the total wage, we want a small ratio.
// So we sort all workers with their expected ratio, and pick up K first worker.
// Now we have a minimum possible ratio for K worker and we their total quality.

// As we pick up next worker with bigger ratio, we increase the ratio for whole group.
// Meanwhile we remove a worker with highest quality so that we keep K workers in the group.
// We calculate the current ratio * total quality = total wage for this group.

// We redo the process and we can find the minimum total wage.
// Because workers are sorted by ratio of wage/quality.
// For every ratio, we find the minimum possible total quality of K workers.

// Using Sorting, Priority Queue(Max Heap) & Greedy Approach
// Time Complexity : O(NLogN)
// Space Complexity : O(N)

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // ratio of wage & quality, quality
        vector<pair<double, double>> workers;
        
        for(int i = 0; i < quality.size(); i++){
            workers.push_back({(double)(wage[i])/quality[i], (double)quality[i]});
        }        
        sort(workers.begin(), workers.end());
        
        double res = DBL_MAX, sumOfQuality = 0;
        priority_queue<int> pq;
        for(auto worker : workers){
            sumOfQuality += worker.second;
            pq.push(worker.second);
            
            if(pq.size() > k){
                sumOfQuality -= pq.top();
                pq.pop();                
            }
            
            if(pq.size() == k){
                res = min(res, sumOfQuality * worker.first);
            }
        }
        
        return res;
    }
};



// Example 
// https://www.youtube.com/watch?v=o8emK4ehhq0

// q = [10, 5, 15];
// w = [80, 35, 30];
// k = 2;

// ans = 120;
