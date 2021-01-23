
// Question) 1732. Find the Highest Altitude


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int largestAltitude(vector<int>& gain) {
    int maxPoint = 0, temp = 0;
    for(int itr = 0; itr < gain.size(); itr++){
        temp = gain[itr]+temp;
        if(temp > maxPoint){
            maxPoint = temp;
        }            
    }
    return maxPoint;
}
