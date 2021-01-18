
// Question) 1281. Subtract the Product and Sum of Digits of an Integer


// Implementation

// 1st Approach in C++
// Time Complexity = O(LogN), Space Complexity = O(1)

int productOfDigit(int n){
    int pod = 1;
    while(n > 0){
        pod *= n%10;
        n /= 10;
    }        
    return pod;
}

int sumOfDigit(int n){
    int sod = 0;
    while(n > 0){
        sod += n%10;
        n /= 10;
    }        
    return sod;
}

int subtractProductAndSum(int n) {
    int pod = productOfDigit(n);
    int sod = sumOfDigit(n);
    return pod - sod;        
}


// 2nd Approach in Java
// Time Complexity = O(LogN), Space Complexity = O(1)

int productOfDigit(int n){
    int pod = 1;
    while(n > 0){
        pod *= n%10;
        n /= 10;
    }        
    return pod;
}

int sumOfDigit(int n){
    int sod = 0;
    while(n > 0){
        sod += n%10;
        n /= 10;
    }        
    return sod;
}

public int subtractProductAndSum(int n) {
    int pod = productOfDigit(n);
    int sod = sumOfDigit(n);
    return pod - sod;        
}
