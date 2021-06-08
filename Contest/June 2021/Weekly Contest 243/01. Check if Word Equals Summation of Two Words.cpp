
// Question) 1880. Check if Word Equals Summation of Two Words


// Implementation

// 1st Approach in C++
// Time Complexity = O(str.length()), Space Complexity = O(1)

int sumOfWord(string str){
    int sum = 0, itr = str.length(), jtr = 0;        
    while(jtr < itr) sum = sum * 10 + ((str[jtr++]) - 97);
    return sum;
}

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    if((sumOfWord(firstWord) + sumOfWord(secondWord)) == sumOfWord(targetWord)) return true;
    else return false;
}
