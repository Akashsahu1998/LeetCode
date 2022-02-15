
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



// 2nd Approach
// Time Complexity = O(NLogN)
// Space Complexity = O(1)
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {       
        
        // Sort the beans vector
        sort(beans.begin(), beans.end());
        
        // finding the sum of all elements
        long long sum = 0;
        for(auto bean : beans) {
            sum += bean;
        }
        
        // will be storing the result into ans
        long long ans = LLONG_MAX;
        long long size = beans.size();
        
        // multiplying the current element(a) with the size and subtracting it from sum, bcz in this way we can get the minimum number of magic beans that we need to remove to get the current value(a).
        // if that value is minimum then store it into the result
        // simultaneously decrement size by 1
        for(auto a : beans){
            ans = min(ans, sum - (a * size--));
        }
        
        // return result
        return ans;
    }
};
