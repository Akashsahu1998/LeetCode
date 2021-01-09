
// Question-1) 1716. Calculate Money in Leetcode Bank


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int totalMoney(int n) {
    int money = 0, mondayMoney = 1, weekMoney = 1;
    for(int itr = 1; itr <= n; itr++){
        if(itr % 7 == 0){
            money += weekMoney;
            weekMoney = ++mondayMoney;
        } 
        else money += weekMoney++;         
    }
    return money;
}
