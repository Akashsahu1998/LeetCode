class UnionFindSet {
public:
    UnionFindSet(int n) : init(n) {
        for (int i=0; i<n; i++) {
            init[i] = i;
        }
    }
    
    void Union(int x, int y) {
        init[findUfs(x)] = init[findUfs(y)];
    }
    
    int findUfs(int x) {
        if (init[x] != x) init[x] = findUfs(init[x]);
        return init[x];
    }
    
private:
    vector<int> init;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int maxElem = *max_element(A.begin(), A.end());
        UnionFindSet ufs(maxElem + 1);
        for (int &a : A) {
            for (int k = 2; k <= sqrt(a); k++) {
                if (a % k == 0) {
                    ufs.Union(a, k);
                    ufs.Union(a, a / k);
                }
            }
        }
        unordered_map<int, int> ump;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++ump[ufs.findUfs(a)]);
        }
        return ans;
    }
};
