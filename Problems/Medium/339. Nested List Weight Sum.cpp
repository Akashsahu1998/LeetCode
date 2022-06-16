
// Question) 339. Nested List Weight Sum


// Implementation

// DFS Approach
// Using Recursion
// Time Complexity : O(N), Where N is the total number of nested elements in the input list, i.e [[[[[1]]]], 2] contains 4 nested lists and 2 nested integers, so N = 6 in this case
// Space Complexity : O(D), Where D is the number of recursive calls made, in the worst case the S.C will become O(N), i.e [[[[[[]]]]]]
    
class Solution {
private:
    int dfs(vector<NestedInteger>& nestedList, int depth){
        int total = 0;
        
        for(auto nested : nestedList){
            if(nested.isInteger()){
                total += depth * nested.getInteger();
            }
            else{
                total += dfs(nested.getList(), depth+1);
            }
        }
        
        return total;
    }
    
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};




// BFS Approach
// Using Queue
// Time Complexity : O(N), Where N is the total number of nested elements in the input list, i.e [[[[[1]]]], 2] contains 4 nested lists and 2 nested integers, so N = 6 in this case
// Space Complexity : O(N), in the worst case the S.C will become O(N), i.e [1, 2, 3, 4, 5]

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> bfsQueue;
        for(auto nested : nestedList){
            bfsQueue.push(nested);
        }
        
        int depth = 1, total = 0;
        while(!bfsQueue.empty()){

            int size = bfsQueue.size();
            for(int i = 0; i < size; i++){
                auto front = bfsQueue.front();
                bfsQueue.pop();
                
                if(front.isInteger()){
                    total += depth * front.getInteger();
                }
                else{
                    for(auto nested : front.getList()){
                        bfsQueue.push(nested);
                    }
                }
            }
            
            // increase the depth
            depth++;
        }
        
        return total;
    }
};
