
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
