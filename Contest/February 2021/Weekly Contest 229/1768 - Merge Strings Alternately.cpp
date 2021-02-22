
// Question) 1768. Merge Strings Alternately


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

string mergeAlternately(string word1, string word2) {
    string result;
    int itr = 0, jtr = 0, ktr = 0;
    
    while( (itr < word1.size()) || (jtr < word2.size())){
        if(itr < word1.size()){
            if(ktr % 2 == 0){
                result += word1[itr++];
            }                
        }
        
        if(jtr < word2.size()){
            if(ktr % 2 == 1){
                result += word2[jtr++];
            }
        }
        ktr++;
    }
    return result;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public String mergeAlternately(String word1, String word2) {
    String result = "";
    int itr = 0, jtr = 0, ktr = 0;
    
    while( (itr < word1.length()) || (jtr < word2.length())){
        if(itr < word1.length()){
            if(ktr % 2 == 0){
                result += word1.charAt(itr++);
            }                
        }
        
        if(jtr < word2.length()){
            if(ktr % 2 == 1){
                result += word2.charAt(jtr++);
            }
        }
        ktr++;
    }
    return result;
}
