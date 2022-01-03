
// Question) 997. Find the Town Judge


// Implementation

// Idea
// 1). The judge believes no one.
// 2). Everybody believes judge.
// From these two points, we can say that if any person is trusted by N - 1 persons 
// and the same person trust no one, then we can say that he is a town judge.

// Time Complexity = O(N) + O(trust.size()) => O(N)
// Space Complexity = O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> peopleTrust(n+1, 0);
        
        for(int itr = 0; itr < trust.size(); itr++){
            peopleTrust[trust[itr][0]]--;   // People Who Trust
            peopleTrust[trust[itr][1]]++;   // People Who Don't Trust
        }
        
        for(int itr = 1; itr < n+1; itr++){
            if(peopleTrust[itr] == n-1) return itr;
        }
        
        return -1;
    }
};

// Test Cases

// 2
// [[1,2]]
// 3
// [[1,2],[2,3]]
// 4
// [[1,2],[2,3],[3,4]]
// 5
// [[1,2],[2,3],[4,5]]
// 3
// [[1,3],[2,3]]

// ans
// 2
// -1
// -1
// -1
// 3
