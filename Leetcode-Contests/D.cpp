#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {        
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(i);
            graph[edges[i][1]].push_back(i);
        }
        
        vector<int> d(n, 1e9);
        d[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, -1});
        vector<vector<int>> par(n);
        while (!pq.empty()) {
            int x = pq.top()[0], u = pq.top()[1], i = pq.top()[2];
            pq.pop();
            // cout << x << ' ' << u << ' ' << i << endl;
            
            if (x != d[u]) {
                continue;
            }
            
            if (i != -1) {
                par[u].push_back(i);
            }
            
            for (int j : graph[u]) {
                int s = edges[j][0], v = edges[j][1], w = edges[j][2];
                
                if (v == u) {
                    v = s;
                }
                
                if (d[v] >= d[u] + w) {
                    d[v] = d[u] + w;
                    pq.push({d[v], v, j});
                }
            }
        }
        
        vector<bool> res(edges.size(), false);
        queue<int> q;
        q.push(n - 1);
        vector<bool> vis(n, false);
        vis[n - 1] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int j : par[u]) {
                int s = edges[j][0], v = edges[j][1], w = edges[j][2];
                
                if (v == u) {
                    v = s;
                }
                
                res[j] = true;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        
        return res;
    }
};
