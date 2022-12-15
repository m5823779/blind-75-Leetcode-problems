class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // method 1: DFS
        // 1. create a hash table to store the graph <node, <neighbors, price>>
        // 2. start from, access all neighbors. until k stop is 0, or the node already been visited.
        // 3. mark the visited node
        for (vector<int> f : flights) mp[f[0]].push_back({f[1], f[2]});

        int ans = INT_MAX;
        
        vector<int> visited(n, 0);
        visited[src] = 1;

        dfs(src, dst, k + 1, visited, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    unordered_map<int, vector<pair<int, int>>> mp;
    void dfs(int src, int dst, int k, vector<int>& visited, int cost, int& ans) {
        if (src == dst) {
            ans = min(ans, cost);
            return;
        }
        if (k == 0) return;
        if (cost > ans) continue;  // prunning

        for (pair<int, int>& neighbor : mp[src]) {
            if (visited[neighbor.first]) continue;  // do not visit the same city twice

            visited[neighbor.first] = 1;
            dfs(neighbor.first, dst, k - 1, visited, cost + neighbor.second, ans); 
            visited[neighbor.first] = 0; 
        }   
    }
    // time complexity: O(n^k+1)
    // space complexity: O(k+1)
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT_MAX;

        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto f : flights) mp[f[0]].push_back( {f[1], f[2]} );

        queue<pair<int, int>> q;
        q.push( {src, 0} );  // current node, current cost

        while (!q.empty() && k-- >= 0) {
            int cur_node = q.front().first;
            int cur_cost = q.front().second;

            q.pop();

            for (pair<int, int> neighbor : mp[cur_node]) {
                if (cur_cost + neighbor.second > ans) continue;
                q.push( {neighbor.first, cur_cost + neighbor.second} );
                if (neighbor.first == dst) 
                    ans = min(ans, cur_cost + neighbor.second);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};