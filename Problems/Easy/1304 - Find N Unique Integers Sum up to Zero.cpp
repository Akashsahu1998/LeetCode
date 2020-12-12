
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


// 2nd Approach in Java

class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        int itr = 0;
        for(int a = -1, b = 1; b <= (n/2); ){
            result[itr++] = b++;
            result[itr++] = a--;
        }
        if(n % 2 == 1) result[itr] = 0;        
        return result;
    }
}
