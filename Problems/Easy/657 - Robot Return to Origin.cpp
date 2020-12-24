
// Question) 657. Robot Return to Origin


// Implementation

// 1st Approach in C++ Using Map
// Time Complexity = O(N), Space Complexity = O(N)

bool judgeCircle(string moves) {
    map<char, int> mp;
    for(int itr = 0; itr < moves.size(); itr++){
        mp[moves[itr]]++;
    }       
    
    if((mp['U'] == mp['D']) && (mp['R'] == mp['L']))
            return true;    
    else
        return false;                
}


// 2nd Approach in C++ Wihtout Using Map
// Time Complexity = O(N), Space Complexity = O(1)

bool judgeCircle(string moves) {
    int a = 0, b = 0;
    for(int itr = 0; itr < moves.size(); itr++){
       if(moves[itr] == 'U') a++; 
       if(moves[itr] == 'D') a--;
       if(moves[itr] == 'R') b++;
       if(moves[itr] == 'L') b--;
    }
    return (a == 0) && (b == 0);
}


// 3rd Approach in Java Wihtout Using Map
// Time Complexity = O(N), Space Complexity = O(1)

public boolean judgeCircle(String moves) {
    int a = 0, b = 0;
    for(int itr = 0; itr < moves.length(); itr++){
        if(moves.charAt(itr) == 'U') a++;
        if(moves.charAt(itr) == 'D') a--;
        if(moves.charAt(itr) == 'R') b++;
        if(moves.charAt(itr) == 'L') b--;            
    }
    return (a == 0) && (b == 0);
}
