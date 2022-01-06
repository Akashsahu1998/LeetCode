
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



// 2nd approach
// By sorting the vector 
// Time Complexity = O(NLogN), Space Complexity = O(N)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
	    vector<pair<int, int>> vec;
                
        for(int itr = 0; itr < trips.size(); itr++){
        	// we are storing the source and number of people who will enter on this source
            vec.push_back({trips[itr][1], trips[itr][0]});
            
            // we are storing the destination and number of people who will exit that's why '-' symbol it means these number of people will go out of car.
            vec.push_back({trips[itr][2], -trips[itr][0]});
        }
        
        // sorting the vector bcz car will move in one direction, so we want the source to destination in increasing order like, 1 2 3 4 5 6 7 8 9....
        sort(vec.begin(), vec.end());
        
        // we are just subtracting the number of people from capacity, if there are more people greater than the capacity than
		// our capacity will go less than 0, so we will return false
        for(auto a : vec){
            capacity -= a.second;
            if(capacity < 0) return false;
        }
        
        return true;
    }
};
