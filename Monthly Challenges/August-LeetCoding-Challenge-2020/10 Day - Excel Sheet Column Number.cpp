// 1st Method Using Power Function

int titleToNumber(string s) {
	int columnNumber = 0;
	for(int itr = 0; itr < s.length(); itr++){
		int temp = pow(26, s.length() - itr - 1);
		temp = temp * (s[itr] - 64);
		columnNumber += temp;
	}		        
	return columnNumber;
}

// 2nd Method Without Using Power Function

int titleToNumber(string s) {
	int columnNumber = 0;
	for(int itr = 0; itr < s.length(); itr++){
		int temp = columnNumber * 26;
		columnNumber = temp + (s[itr] - 64);	
	}		        
	return columnNumber;
}
