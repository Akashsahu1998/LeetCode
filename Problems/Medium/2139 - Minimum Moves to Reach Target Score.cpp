
// Question) 2139. Minimum Moves to Reach Target Score


// Implementation

// reduces target to 1
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int minMoves(int target, int maxDoubles) {        
        if(maxDoubles == 0) return target-1;
        
        int count = 0;
            
        while(target > 1){
            // if maxDoubles are more than 0, and target is even, then we will substract it by 2, otherwise 1
            if(maxDoubles != 0 && target%2 == 0){
                target /= 2;
                maxDoubles--;
            }
            else{
                target -= 1;
            }
            count++;
        }
        
        return count;
    }
};
