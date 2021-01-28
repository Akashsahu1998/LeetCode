
// Question) 1342. Number of Steps to Reduce a Number to Zero


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int numberOfSteps (int num) {
    int count = 0;
    while(num){
        if(num % 2 == 0){
            num /= 2;
        }
        else num -= 1;
        count++;
    }
    return count;
}
