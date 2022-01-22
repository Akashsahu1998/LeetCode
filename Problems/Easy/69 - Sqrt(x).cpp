
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


 2nd Approach
 Time Complexity = O(sqrt(n))
 Space Complexity = O(1)
 class Solution {
 public:
     int mySqrt(int x) {
         int res = 0;
         for(long long int itr = 1; itr <= x; itr++){
             long long int val = itr*itr;
             if(val == x){
                 res = itr;
                 break;
             }
             else if(val > x){
                 res = itr-1;
                 break;
             }
         }
         return res;
     }
 };
