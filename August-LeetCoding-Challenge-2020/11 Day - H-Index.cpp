class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for(int itr = 0; itr < citations.size(); itr++){
            if(citations.size() - itr <= citations[itr]) return citations.size() - itr;
        }
        return 0;
    }
};
