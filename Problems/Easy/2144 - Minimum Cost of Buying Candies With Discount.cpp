
// Question) 2144. Minimum Cost of Buying Candies With Discount


// Implementation

// Using sorting
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        
        // sort the array into descending order
        sort(cost.begin(), cost.end(), greater<int>());
        
        // storing the result
        int totalCount = 0;
        
        // traversing the array, and skipping the every 3rd element, bcz we are buying 1st and 2nd and getting 3rd as a free.
        for(int itr = 0; itr < n; itr++){
            
            // adding every first element
            totalCount += cost[itr];
            
            // checking every 2nd index, if its valid, then add, otherwise break
            if(++itr < n) totalCount += cost[itr];
            else break;
            
            // skipping every 3rd element
            itr++;
        }
        return totalCount;
    }
};
