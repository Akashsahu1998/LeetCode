
// Q2.) 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers.


// Implementation

// 1st Approach in CPP
// Time Complexity = O(N), Space Complexity = O(1)

int minPartitions(string n) {
    int res = 0;        
    for(char ch : n) res = max(ch - '0', res);
    return res;
}
