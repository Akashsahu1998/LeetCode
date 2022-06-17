
// Question) 364. Nested List Weight Sum II


// Implementation

// 1st Approach
// DFS Approach, Double Traversal
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


// 2nd Approach
// BFS Approach, Single Traversal
// Using Queue
// Time Complexity : O(N), Where N is the total number of nested elements in the input list, i.e [[[[[1]]]], 2] contains 4 nested lists and 2 nested integers, so N = 6 in this case
// Space Complexity : O(N), in the worst case the S.C will become O(N), i.e [1, 2, 3, 4, 5]
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int curDepth = 1, maxDepth = 1, sumOfElements = 0, sumOfProducts = 0;
        
        queue<NestedInteger> bfsQueue;
        
        for(auto nested : nestedList){
            bfsQueue.push(nested);
        }
        
        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            maxDepth = max(curDepth, maxDepth);
            
            for(int i = 0; i < size; i++){
                NestedInteger front = bfsQueue.front();
                bfsQueue.pop();
                
                if(front.isInteger()){
                    sumOfElements += front.getInteger();
                    sumOfProducts += front.getInteger() * curDepth;
                }
                else{
                    for(auto nested : front.getList()){
                        bfsQueue.push(nested);
                    }
                }
            }
            
            curDepth++;
        }
        
        // equation to get the results
        return ((maxDepth + 1) * sumOfElements) - sumOfProducts;
    }
};
