
// Question) 1431. Kids With the Greatest Number of Candies


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {        
    int maxCandies = *max_element(candies.begin(), candies.begin()+candies.size());
    vector<bool> result;
    for(int candy : candies){
        if((candy+extraCandies) >= maxCandies){
            result.push_back(true);
        }
        else result.push_back(false);
    }
    return result;
}
