class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ansList;
        int a = 0, b = 0;
        int collection[26];
        for(int itr = 0; itr < S.size(); itr++) collection[S[itr] - 'a'] = itr;
        for(int itr = 0; itr < S.size(); itr++) {
            b = max(b, collection[S[itr] - 'a']);
            if (itr == b) {
                ansList.push_back(b - a + 1);
                a = itr + 1;
                b = a;
            } 
        }
        return ansList;
    }
};
