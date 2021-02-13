
// Question) 1742. Maximum Number of Balls in a Box


// Implementation

// 1st Approach in C
// Time Complexity = O(NLogN), Space Complexity = O(N) where N = 46

int countBalls(int lowLimit, int highLimit){
    int array[46] = {0};
    int max = -1;
    for (int itr = lowLimit; itr <= highLimit; itr++) {
        int sumOfDigit = 0;
        for (int jtr = itr; jtr > 0; jtr /= 10) {
            sumOfDigit += jtr % 10;
        }
        ++array[sumOfDigit];
        if(max < array[sumOfDigit]) max = array[sumOfDigit];        
    }
    return max;
}


// 2nd Approach in C++
// Time Complexity = O(NLogN), Space Complexity = O(N) where N = 46

int countBalls(int lowLimit, int highLimit) {        
    unordered_map<int, int> ump;
    int Max = -1;
    for(int itr = lowLimit; itr <= highLimit; itr++){
        int digitOfSum = 0;
        for(int jtr = itr; jtr > 0; jtr /= 10){
            digitOfSum += jtr%10;
        }
        ump[digitOfSum]++;
        Max = max(Max, ump[digitOfSum]);                                    
    }
    return Max;
}   


// 3rd Approach in Java
// Time Complexity = O(NLogN), Space Complexity = O(N) where N = 46

public int countBalls(int lowLimit, int highLimit) {
    int[] array = new int[46];
    int max = -1;
    for (int itr = lowLimit; itr <= highLimit; itr++) {
        int sumOfDigit = 0;
        for (int jtr = itr; jtr > 0; jtr /= 10) {
            sumOfDigit += jtr % 10;
        }
        ++array[sumOfDigit];
        max = Math.max(max, array[sumOfDigit]);   
    }
    return max;
}
