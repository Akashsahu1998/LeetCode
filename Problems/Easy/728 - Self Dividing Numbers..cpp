
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


// 2nd Approach in Java

public boolean check(int left) {
    int rem, num = left;
    while(num != 0){
        rem = num % 10;
        if(rem == 0) return false;
        if(left % rem != 0){
            return false;                
        }
        num /= 10;            
    }
    return true;
}

public List<Integer> selfDividingNumbers(int left, int right) {
    List<Integer> list=new ArrayList<Integer>();
    while(left <= right){
        if(check(left)) list.add(left);
        left++;
    }
    return list;
}
