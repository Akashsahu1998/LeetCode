class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0) 
            return false; 
        return floor(logn(num, 4))==ceil(logn(num, 4));
    }
    
private:
    float logn(int num, int r) 
    { 
        return log(num) / log(r); 
    }
};
