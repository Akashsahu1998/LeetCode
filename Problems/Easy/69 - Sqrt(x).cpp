
// Question) 69. Sqrt(x)


// Implementation


// 1st Approach
// Using Sqrt function
// Time Complexity = O(sqrt(n))
// Space Complexity = O(1)
// class Solution {
// public:
//     int mySqrt(int x) {
//         return sqrt(x);
//     }
// };


// 2nd Approach
// Time Complexity = O(sqrt(n))
// Space Complexity = O(1)
// class Solution {
// public:
//     int mySqrt(int x) {
//         int res = 0;
//         for(long long int itr = 1; itr <= x; itr++){
//             long long int val = itr*itr;
//             if(val == x){
//                 res = itr;
//                 break;
//             }
//             else if(val > x){
//                 res = itr-1;
//                 break;
//             }
//         }
//         return res;
//     }
// };


// 3rd Approach
// Using Binary Search
// Time Complexity = O(LogN)
// Space Complexity = O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        long long ans = 0, low = 1, high = x/2;
        while(low <= high){
            
            long long mid = low + (high - low)/2;
            
            long long sqrt = (mid*mid);
                        
            if(sqrt == x) return mid;
            
            if(sqrt > x) high = mid-1;
            else{
                low = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};
