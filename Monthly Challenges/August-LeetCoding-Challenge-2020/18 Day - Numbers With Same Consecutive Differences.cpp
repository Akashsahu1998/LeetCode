
// Using DFS

class Solution {
public:    
    int countDigits(int num){
        int countDig = 0;
        while(num){
            countDig++;
            num = num / 10;
        }        
        return countDig;
    }
    
    void findNumbers(int currentIndex, int N ,int K, vector<int> &answer){
        if(countDigits(currentIndex) == N){
            answer.push_back(currentIndex);
            return;
        }
        
        for(int index = 0; index < 10; index++){ 
           int lastDigit = currentIndex % 10;            
           if(abs(lastDigit - index) == K) findNumbers((currentIndex * 10 + index), N, K, answer);
        }
        
    }  
    
    vector<int> numsSameConsecDiff(int N, int K) {        
        vector<int> answer;             
        if(N == 1) answer.push_back(0);        
        for(int index = 1; index < 10; index++) findNumbers(index, N, K, answer);
        return answer;              
    }
};
