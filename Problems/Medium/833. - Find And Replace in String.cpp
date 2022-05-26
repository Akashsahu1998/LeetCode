
// Question) 833. Find And Replace in String


// Implementation


// Time Complexity = O(SN), Where S is the size of s, and N means size of indices
// Space Complexity = O(N)
// Idea : 1) Sort the indices in descending order by preserving the occurence of the index of the value
//		  2) Iterate from back and perform normal operations.

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> indicesInDescendingOrder;
        for(int i = 0; i < indices.size(); i++){
            indicesInDescendingOrder.push_back({indices[i], i});
        }
        
        sort(indicesInDescendingOrder.rbegin(), indicesInDescendingOrder.rend());
        
        for(int i = 0; i < indicesInDescendingOrder.size(); i++){
            int indicesIndex = indicesInDescendingOrder[i].first;
            int sourcesIndex = indicesInDescendingOrder[i].second;
            
            string sourcesStr = sources[sourcesIndex];
            if(s.substr(indicesIndex, sourcesStr.size()) == sourcesStr){
                s = s.substr(0, indicesIndex) + targets[sourcesIndex] + s.substr(indicesIndex + sourcesStr.size());
            }
        }
        
        return s;
    }
};
