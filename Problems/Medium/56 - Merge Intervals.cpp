
// Question) 56. Merge Intervals


// Implementation

// Using Sorting
// Time Complexity: O(NLogN)
// Space Complexity: O(1), not considering the res vector of vector, bcz that's a part of o/p
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        // sort the vector
        sort(intervals.begin(), intervals.end());
        
        // inserting the 0th index value into tempInterval vector
        // tempInterval it will take constant space, bcz the size of this vector will always remains 2 only
        vector<int> tempInterval = intervals[0];
        
        // iterating from 1, and checking if the current itr index value lies into the interval of tempInterval vector
        // if lies then we will take the maximum value of the end interval, and store into tempInterval[1] position
        // if didn't lies, it means we got the first merged interval, and will store into the res, after that we will put the current itr index value of intervals into tempInterval vector to check the next element
        for(int itr = 1; itr < intervals.size(); itr++){
            if(intervals[itr][0] <= tempInterval[1]){
                tempInterval[1] = max(intervals[itr][1], tempInterval[1]);
            }
            else{
                res.push_back(tempInterval);
                tempInterval = intervals[itr];
            }
        }
        res.push_back(tempInterval);
        
        return res;
    }
};


//Another Approach
// -> this solution is also working
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        int smallValue = intervals[0][0], bigValue = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(bigValue >= intervals[i][0]){
                bigValue = max(bigValue, intervals[i][1]);
            }
            else{
                res.push_back({smallValue, bigValue});
                smallValue = intervals[i][0];
                bigValue = intervals[i][1];
            }
        }
        res.push_back({smallValue, bigValue});
        return res;
    }
};



// Algo Steps
// 1) Use sorting & after that just check adjacent elements, according to small & big
