
// Question) 339. Nested List Weight Sum


// Implementation

// Using DFS
// Time Complexity : O(N), Where is the total number of nested elements in the input list, i.e [ [[[[1]]]], 2] contains 44 nested lists and 22 nested integers, so N = 6 in this case
// Space Complexity : O(D), Where D is the number of recursive calls made, in the worst case the S.C will becomd O(N), i.e ([[[[[[]]]]]])
    
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
