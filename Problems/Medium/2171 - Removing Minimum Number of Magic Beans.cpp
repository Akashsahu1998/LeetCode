
// Question) 2171. Removing Minimum Number of Magic Beans


// Implementation

// 1st Approach
// Time Complexity = O(NLogN)
// Space Complexity = O(1)

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long minCount = LLONG_MAX;
        
        sort(beans.begin(), beans.end());
        
        long long cnt = 0;
        for(long long itr = 0; itr < beans.size(); itr++){
            cnt += beans[itr];
        }
        
        if(minCount > cnt){
            minCount = cnt;
        }
        
        long long zeroCount = 0;
        for(long long itr = 0; itr < beans.size()-1; itr++){
            cnt -= beans[itr];            
            
            long long totalEle = ((beans.size()-1) - itr);
            
            long long totalEleSum = beans[itr] * totalEle;
            
            long long total = cnt - totalEleSum;
            
            if(total + zeroCount < minCount){
                minCount = total + zeroCount;
            }
            zeroCount += beans[itr];
        }
        if(zeroCount < minCount){
            minCount = zeroCount;
        }
        return minCount;
    }
};
