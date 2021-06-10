
// Question) 821. Shortest Distance to a Character


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> shortestToChar(string s, char c) {
    vector<int> vec, res;
    for(int itr = 0; itr < s.size(); itr++){
        if(s[itr] == c) vec.push_back(itr);
    }
    
    int dif1 = 0, dif2 = 0;
    
    for(int jtr = 0, itr = 0; itr < s.size(); itr++){
        if(vec[jtr] >= itr || jtr+1 == vec.size()) res.push_back(abs(vec[jtr]-itr));
        else{
            dif1 = abs(vec[jtr+1]-itr);
            dif2 = abs(vec[jtr]-itr);

            if(dif1 <= dif2){
                res.push_back(dif1);
                jtr++;
            }
            else res.push_back(dif2);
        }
    }
    return res;        
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int[] shortestToChar(String s, char c) {
    ArrayList<Integer> arr = new ArrayList<Integer>();        
    for(int itr = 0; itr < s.length(); itr++){
        if(s.charAt(itr) == c) arr.add(itr);
    }
    int[] res = new int[s.length()];
    int dif1 = 0, dif2 = 0;
    
    for(int jtr = 0, itr = 0; itr < s.length(); itr++){
        if(arr.get(jtr) >= itr || jtr+1 == arr.size()) res[itr] = Math.abs(arr.get(jtr)-itr);
        else{                
            dif1 = Math.abs(arr.get(jtr+1)-itr);
            dif2 = Math.abs(arr.get(jtr)-itr);

            if(dif1 <= dif2){
                res[itr] = dif1;
                jtr++;
            }
            else res[itr] = dif2;
        }
    }
    return res; 
}

