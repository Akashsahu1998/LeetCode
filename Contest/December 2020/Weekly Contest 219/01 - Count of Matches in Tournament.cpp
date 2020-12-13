
// Q1.) 1688. Count of Matches in Tournament

// Implementation
// Time Complexity = O(M * N)


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


