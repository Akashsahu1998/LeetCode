
// Question) 1694. Reformat Phone Number


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

string reformatNumber(string number) {
    string str = "";
    for(int itr = 0; itr < number.length(); itr++){
        if((number[itr] != ' ') && (number[itr] != '-')){
            str = str + number[itr];
        }
    }
    
    string ans = "";
    int len = str.length();
    int rem = len % 3, div = len / 3;
    
    if(rem == 0){
        int cnt = 0;
        for(int itr = 0; itr < len; itr++){
            
            ans = ans + str[itr];
            cnt++;    
            
            if(cnt == 3 && itr != len-1){
                ans = ans + '-';
                cnt = 0;
            }
        }
    }
    else if(rem == 1){
        if (div != 0){
            div--;
            rem++;
        }
        int itr = 0, cnt = 0, n = div*3;
        for( ; itr < n; itr++){
            ans = ans + str[itr];
            cnt++;    
            
            if(cnt == 3){
                ans = ans + '-';
                cnt = 0;
            }
        }
        
        cnt = 0;            
        for(int itr = n ; itr < len; itr++){
            ans = ans + str[itr];
            cnt++;    
            
            if(cnt == 2 && itr != len-1){
                ans = ans + '-';
                cnt = 0;
            }
        }            
    }
    else if(rem == 2){
        rem--;
        int itr = 0, cnt = 0, n = div*3;
        for( ; itr < n; itr++){
            ans = ans + str[itr];
            cnt++;    
            
            if(cnt == 3){
                ans = ans + '-';
                cnt = 0;
            }
        }
        
        cnt = 0;            
        for(int itr = n ; itr < len; itr++){
            ans = ans + str[itr];
            cnt++;    
            
            if(cnt == 2 && itr != len-1){
                ans = ans + '-';
                cnt = 0;
            }
        }
    }
    return ans;
}
