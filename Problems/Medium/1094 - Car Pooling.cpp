
// Question) 19. Remove Nth Node From End of List


// Implementation

// 1st approach
// Using map
// Time Complexity = O(NLogN), Space Complexity = O(N)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
		// map bcz, here car is moving in one direction it means in increasing order, thats why we took map, and
		// In map we are storing the key as a source and destination, so it will be always in a sorted order
        map<int, int> mp;
        
        // In the place of source we are adding the no. of persons, bcz that is the place where those no. of persons are entering, and
		// In destination we are removing the no. of persons bcz thats the place were no. persons are going out from car
        for(int itr = 0; itr < trips.size(); itr++){
            mp[trips[itr][1]] += trips[itr][0];
            mp[trips[itr][2]] += -trips[itr][0];
        }
        
        // If our capacity is less than 0 it means, we are having more number of people(capacity full) before destination, so returning false
        for(auto m : mp){
            capacity -= m.second;
            if(capacity < 0) return false;
        }
        
        return true;
    }
};
