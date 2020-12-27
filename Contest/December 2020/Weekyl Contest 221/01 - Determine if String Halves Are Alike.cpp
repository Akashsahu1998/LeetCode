
// Question) 1704. Determine if String Halves Are Alike


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

bool halvesAreAlike(string str) {
    int count1 = 0, count2 = 0;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int itr = 0; itr < (str.size()/2); itr++){
        if((str[itr] == 'a') || (str[itr] == 'e') || (str[itr] == 'i') || (str[itr] == 'o') || (str[itr] == 'u'))
            count1++;
    }
    for(int itr = (str.size()/2); itr < str.size(); itr++){
        if((str[itr] == 'a') || (str[itr] == 'e') || (str[itr] == 'i') || (str[itr] == 'o') || (str[itr] == 'u'))
            count2++;
    }
    if(count1 == count2) return true;
    return false;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public boolean halvesAreAlike(String str) {
    int count1 = 0, count2 = 0;
    str = str.toLowerCase(); 
    for(int itr = 0; itr < (str.length()/2); itr++){
        if((str.charAt(itr) == 'a') || (str.charAt(itr) == 'e') || (str.charAt(itr) == 'i') || (str.charAt(itr) == 'o') || (str.charAt(itr) == 'u'))
            count1++;
    }
    for(int itr = (str.length()/2); itr < str.length(); itr++){
        if((str.charAt(itr) == 'a') || (str.charAt(itr) == 'e') || (str.charAt(itr) == 'i') || (str.charAt(itr) == 'o') || (str.charAt(itr) == 'u'))
            count2++;
    }
    if(count1 == count2) return true;
    return false;
}
