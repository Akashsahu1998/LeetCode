class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> mp, string source, string destination, unordered_map<string,int> &visited, double &ans, double temp) {
        
        if(visited.count(source))
            return;

        visited[source] = 1;

        if(source == destination) {
            ans = temp;
            return;
        }

        for(auto a : mp[source]) {
            dfs(mp, a.first, destination, visited,ans, temp * a.second);
        }
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mp;
    
        for(int itr = 0; itr < equations.size(); itr++) {
            mp[equations[itr][0]].push_back({equations[itr][1], values[itr]});
            mp[equations[itr][1]].push_back({equations[itr][0], 1.0/values[itr]});
        }

        vector<double> v; 
        for(int itr = 0; itr < queries.size(); itr++) {
            string s = queries[itr][0];
            string d = queries[itr][1];
            double ans = -1;
            unordered_map<string,int> visited;
            if(mp.count(s))
            dfs(mp, s, d, visited, ans, 1.0);
            v.push_back(ans);
        }

        return v;
    }
};
