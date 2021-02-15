
// Question) 1337. The K Weakest Rows in a Matrix


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(Number of rows) 

vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
    set<pair<int, int>> st;
    for (auto itr = 0; itr < matrix.size(); itr++) {
        auto p = accumulate(begin(matrix[itr]), end(matrix[itr]), 0);
        st.insert({p, itr});
    }
    vector<int> res;
    for (auto itr = begin(st); k > 0; itr++, k--)
        res.push_back(itr->second);
    return res;
}
