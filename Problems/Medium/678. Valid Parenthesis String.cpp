
// Question) 678. Valid Parenthesis String


// Implementation

// Video link : https://www.youtube.com/watch?v=KuE_Cn3xhxI
// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
	bool checkValidString(string str) {
	 stack<char> star, open;
	
	 for(int itr = 0; itr < str.size(); itr++){
	     if(str[itr] == '(') open.push(itr);
	     else if(str[itr] == '*') star.push(itr);
	     else{
	         if(!open.empty()) open.pop();
	         else if(!star.empty()) star.pop();
	         else return false;
	     }
	 }
	
	 while(!open.empty()){
	     if(star.empty()) return false;
	     else if(open.top() < star.top()){
	         open.pop();
	         star.pop();
	     }
	     else return false;
	 }        
	
	 return true;
	}
};


// Reference link-1 : https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis
// Reference link-2 : https://leetcode.com/problems/valid-parenthesis-string/discuss/543521/Java-Count-Open-Parenthesis-O(n)-time-O(1)-space-Picture-Explain
// Reference link-3 : https://leetcode.com/problems/valid-parenthesis-string/discuss/107577/Short-Java-O(n)-time-O(1)-space-one-pass

// Efficient Solution
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    bool checkValidString(string str) {
        int high = 0, low = 0;
        
        for(auto itr : str){
            if(itr == '('){
                high++;
                low++;
            }
            else if(itr == ')'){
                high--;
                if(low > 0) low--;
            }
            else{
                high++;
                if(low > 0) low--;
            }
            
            // it means Currently, don't have enough open parentheses to match close parentheses->
            // For example: "())(" or ")*"
            if(high < 0) return false
        }
        
        return (low == 0);
    }
};

// Test cases

//	"*("	=> T
//	"(*("	=> F
//	"(*"	=> F
//	"**"	=> T
//	"(*)"	=> T
//	"()"	=> T
//	"(*))"	=> T
//	")(("	=> F
//	"()))("	=> F
//	"(*))"	=> T
//	"*(()"	=> F
//	"*(())"	=> T
