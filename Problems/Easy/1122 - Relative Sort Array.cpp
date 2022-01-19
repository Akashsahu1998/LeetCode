
// Question) 1122. Relative Sort Array


// Implementation

// Using unordered_map
// Time Complexity = O(N * Log(N)), Space Complexity = O(N)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // taking res vector to store the result elements
        vector<int> res;
        
        // taking a map to store the frequency of elements of arr1
        unordered_map<int, int> mp;
        
        // store the frequency of elements of arr1
        for(auto a : arr1){
            mp[a]++;
        }
        
        // iterating over arr2, and
        // checking if element of arr2 is present into mp, then simple taking its frequency and adding the number that much time into the result
        // in last delete that element from mp
        for(auto a : arr2){
            if(mp[a]){
                int count = mp[a];
                
                for(int jtr = 0; jtr < count; jtr++){
                    res.push_back(a);
                }
                
                mp.erase(a);
            }
        }
        
        // storing the remaining elements left in mp, bcz we need to sort them in ascending order
        vector<int> remainingElements;
        for(auto m : mp){
            int count = m.second;
            for(int jtr = 0; jtr < count; jtr++){
                remainingElements.push_back(m.first);
            }
        }
    
        // sorting the remaining elements into natural ascending order        
        sort(remainingElements.begin(), remainingElements.end());
        
        // after sorting just adding them into the res vector
        for(auto a : remainingElements){
            res.push_back(a);
        }
        
        return res;
    }
};
