
// Q1.) 1688. Count of Matches in Tournament

// Implementation

// 1st Approach in CPP
// Time Complexity = O(log N), Space Complexity = O(Log N)

int numberOfMatches(int n) {
    int cnt = 0; 
    while(n != 1){
        if(n % 2){      // odd                
            cnt += (n / 2);
            n = (n / 2) + 1;
        }
        else{
            cnt += n / 2;
            n = n / 2;
        }
    }
    return cnt;
}


// 2nd Approach in CPP
// Time Complexity = O(1), Space Complexity = O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        return (n - 1);
    }
};


// 3rd Approach in Java
// Time Complexity = O(log N), Space Complexity = O(Log N)

class Solution {
    public int numberOfMatches(int n) {
        int cnt = 0; 
        while(n != 1){
            if(n % 2 == 1){
			    cnt += (n / 2);
                n = (n / 2) + 1;
            }
            else{
                cnt += n / 2;
                n = n / 2;
            }
        }
        return cnt;
    }
}


// 4th Approach in Java
// Time Complexity = O(1), Space Complexity = O(1)

class Solution {
    public int numberOfMatches(int n) {        
        return (n - 1);
    }
}

