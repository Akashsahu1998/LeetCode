
// Question) 2177. Find Three Consecutive Integers That Sum to a Given Number


// Implementation

// Brute Force
// Giving TLE
// Time Complexity = O(N/3) => O(N), where N is num
// Space Complexity = O(1), not considering the res vector, bcz its a part of result
class Solution {
public:
    vector<long long> sumOfThree(long long num) {        
        for(long long itr = -1; itr <= num/3; itr++){
            long long sum = itr + (itr+1) + (itr+2);
            if(sum == num){
                return {itr, itr+1, itr+2};
                break;
            }
        }
        return {};
    }
};


// Efficient Solution
// Time Complexity = O(1)
// Space Complexity = O(1)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long sum = num/3;
        if(((sum-1) + sum + (sum+1)) == num){
            return {sum-1, sum, sum+1};
        }
        return {};
    }
}; 
