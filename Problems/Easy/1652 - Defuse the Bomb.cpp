
// Question) 1652. Defuse the Bomb


// Implementation

// 1st Approach in C++
// Time Complexity = O(N*K), Space Complexity = O(N)

vector<int> decrypt(vector<int>& code, int k) {
    if(k == 0){
        vector<int> vect(code.size(), 0);
        return vect;
    }        
    vector<int> vect;
    int n = code.size();
    if(k > 0){            
        for(int itr = 0; itr < n; itr++){
            int cnt = k, jtr, total = 0;                 
            if(itr == n-1) jtr = 0;
            else jtr = itr+1;                    
            for( ; jtr < n; jtr++){
                cnt--;
                total += code[jtr];                    
                if(cnt == 0) break;                    
                if(jtr == n-1) jtr = -1;
            }
            vect.emplace_back(total);
        }            
    }
    else{
        k = k * -1;
        for(int itr = 0; itr < n; itr++){
            int cnt = k, jtr, total = 0;
            if(itr == 0) jtr = n-1;
            else jtr = itr-1;
            for( ; jtr > -1; jtr--){
                cnt--;
                total += code[jtr];
                if(cnt == 0) break;
                if(jtr == 0) jtr = n;
            }
            vect.emplace_back(total);
        }
    }
    return vect;
}


// 2nd Approach in Java
// Time Complexity = O(N*K), Space Complexity = O(N)

public int[] decrypt(int[] code, int k) {
    int n = code.length;
    if(k == 0){
        for(int itr = 0; itr < n; itr++)
            code[itr] = 0;
        return code;            
    }        
    int[] arr = new int[n];
    int index = 0;
    if(k > 0){            
        for(int itr = 0; itr < n; itr++){
            int cnt = k, jtr, total = 0;                 
            if(itr == n-1) jtr = 0;
            else jtr = itr+1;                    
            for( ; jtr < n; jtr++){
                cnt--;
                total += code[jtr];                    
                if(cnt == 0) break;                    
                if(jtr == n-1) jtr = -1;
            }
            arr[index++] = total;
        }            
    }
    else{
        k = k * -1;
        for(int itr = 0; itr < n; itr++){
            int cnt = k, jtr, total = 0;
            if(itr == 0) jtr = n-1;
            else jtr = itr-1;
            for( ; jtr > -1; jtr--){
                cnt--;
                total += code[jtr];
                if(cnt == 0) break;
                if(jtr == 0) jtr = n;
            }
            arr[index++] = total;
        }
    }
    return arr;
}
