
// Question) 461. Hamming Distance


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

int hammingDistance(int x, int y) {
    vector<int> v1;
    vector<int> v2;
    while(x != 0 || y != 0){
        v1.push_back(x%2);
        v2.push_back(y%2);
        x /= 2;
        y /= 2;
    }
    int cnt = 0;
    for(int itr = 0; itr < v1.size(); itr++){
        if(v1[itr] != v2[itr]) cnt++;
    }
    return cnt;
}
