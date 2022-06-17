
// Question) 364. Nested List Weight Sum II


// Implementation

// DFS Approach
// Using Recursion
// Time Complexity : O(2N) => O(N), Where N is the total number of nested elements in the input list, i.e [[[[[1]]]], 2] contains 4 nested lists and 2 nested integers, so N = 6 in this case
// Space Complexity : O(D), Where D is the number of recursive calls made, in the worst case the S.C will become O(N), i.e [[[[[[]]]]]]

class Solution {
private:
    void findMaxDepth(vector<NestedInteger>& nestedList, int curDepth, int &maxDepth){
        maxDepth = max(curDepth, maxDepth);
        for(auto nested : nestedList){
            if(!nested.isInteger()){
                findMaxDepth(nested.getList(), curDepth+1, maxDepth);
            }
        }
    }
    
    int dfs(vector<NestedInteger>& nestedList, int curDepth, int maxDepth){
        int total = 0;
        for(auto nested : nestedList){
            if(nested.isInteger()){
                total += (maxDepth - curDepth + 1) * nested.getInteger();
            }
            else{
                total += dfs(nested.getList(), curDepth+1, maxDepth);
            }
        }
        return total;
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 1;
        findMaxDepth(nestedList, 1, maxDepth);
        return dfs(nestedList, 1, maxDepth);
    }
};
