
// Question) 50. Pow(x, n)


// Implementation


// Using Simple Maths
// Time Complexity = O(LogN)
// Space Complexity = O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        
        long nn = n;
        if(nn < 0) nn *= -1;
        
        while(nn > 0){
            if(nn % 2){
                ans *= x;
                nn--;
            }
            else{
                x *= x;
                nn /= 2;
            }
        }
        
        return (n < 0) ? 1/ans : ans;
    }
};
