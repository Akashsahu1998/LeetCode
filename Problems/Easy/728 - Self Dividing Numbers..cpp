
// Question) 728. Self Dividing Numbers.


// Implementation

// 1st Approach in C++

bool check(int left) {
    int rem, num = left;
    while(num){
        rem = num % 10;
        if(rem == 0) return false;
        if(left % rem){
            return false;                
        } 
        num /= 10;            
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right) {   
    vector<int> vect;
    while(left <= right){
        if(check(left)) vect.emplace_back(left);
        left++;            
    }
    return vect;    
}
