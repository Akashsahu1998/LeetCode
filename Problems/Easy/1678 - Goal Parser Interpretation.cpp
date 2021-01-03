
// Question) 1678. Goal Parser Interpretation


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

string interpret(string command) {
    string res = "";
    for(int itr = 0; itr < command.size(); itr++){
        if(command[itr] == 'G') res += 'G';
        else if(command[itr] == '(' && command[itr+1] == ')'){
            res += 'o';
            itr++;
        } 
        else{
             res += "al";
            itr += 3;
        }
    }
    return res;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public String interpret(String command) {
    String res = "";
    for(int itr = 0; itr < command.length(); itr++){
        if(command.charAt(itr) == 'G') res += 'G';
        else if(command.charAt(itr) == '(' && command.charAt(itr+1) == ')'){
            res += 'o';
            itr++;
        } 
        else{
             res += "al";
            itr += 3;
        }
    }
    return res;
}
