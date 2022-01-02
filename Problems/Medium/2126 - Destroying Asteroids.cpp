
// Question) 2126. Destroying Asteroids


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int massCopy = mass;
        sort(asteroids.begin(), asteroids.end());
        
        for(int itr = 0; itr < asteroids.size(); itr++){
            if(massCopy >= asteroids[itr]){
                massCopy += asteroids[itr];
            }
            else return false;
        }
        return true;
    }
};
