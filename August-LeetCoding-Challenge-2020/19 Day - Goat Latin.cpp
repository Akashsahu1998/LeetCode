
// Time Complexity O(n)

class Solution {
public:
    string toGoatLatin(string S) {
        string goatLatin = "";
        string vowels = "aeiouAEIOU";
        int countA = 1;
        istringstream streamObj(S);
        
        while(streamObj){
            string wordFromstreamObj;
            streamObj >> wordFromstreamObj; // scanning the object from string
            
            // cheking if the word is empty or not
            if(wordFromstreamObj.empty() == 0){
                size_t found = vowels.find(wordFromstreamObj[0]); 
                // vowel find
                if(found != string::npos){
                    goatLatin += wordFromstreamObj + "ma";        
                }
                else{   // consonant find
                    goatLatin += wordFromstreamObj.substr(1, wordFromstreamObj.length() - 1);        
                    goatLatin = goatLatin + wordFromstreamObj[0] + "ma";
                }
				                
                // adding the 'a' 
                string strA(countA, 'a');   // making the string of 'a' of size countA
                goatLatin += strA + " ";    // adding that string to our answer string
            }            
            countA++;   // increasing the count of A
        }
        goatLatin = goatLatin.substr(0, goatLatin.length() - 1);
        return goatLatin;
    }
};
