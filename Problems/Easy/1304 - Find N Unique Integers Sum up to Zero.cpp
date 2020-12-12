
// Question) 1304. Find N Unique Integers Sum up to Zero

// Implementation


// 1st Approach in C++

class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> result;        
        for(int a = -1, b = 1; b <= (n/2); ){
            result.push_back(b++);
            result.push_back(a--);            
        }
        if(n % 2) result.push_back(0);        
        return result;
    }
};
