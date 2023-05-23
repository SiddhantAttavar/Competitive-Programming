#include "cyberland.h"

#include <vector>

#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl;
// #define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
/* 
void dfs(int u) {
    visited[u] = true;
    for (pair<int, int> p : graph[u]) {
        if (!visited[p.first]) {
            dfs(p.first);
        }
    }
}

double dijkstras(int n, vector<int> &arr, int h) {
    // Setup priority queue for dijkstras
    vector<double> d(n, 1e15);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    set <int> s;
    range(i, 0, n) {
        if (visited[i] and arr[i] == 0) {
            s.insert(i);
        }
    }
    s.insert(0);

    d[h] = 0;
    pq.push({0, h});
    while (!pq.empty()) {
        int u;
        double x;
        tie(x, u) = pq.top();
        pq.pop();

        if (s.count(u)) {
            return x;
        }

        // print(u, x);
        // print(graph[u].size());

        for (pair<int, int> p : graph[u]) {
            int v, w;
            tie(v, w) = p;
            // print(v, w);
            if ((x + w) < d[v]) {
                d[v] = x + w;
                pq.push({d[v], v});
            }
        }
    }

    return -1;
}

double solve(int n, int m, int k, int h, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    // Create graph
    graph.clear();
    graph.resize(n);
    range(i, 0, m) {
        graph[x[i]].push_back({y[i], c[i]});
        graph[y[i]].push_back({x[i], c[i]});
    }

    // Find adouble reachable nodes using dfs
    visited.clear();
    visited.resize(n);
    dfs(0);

    // Run dijkstras
    return dijkstras(n, arr, h);
} */

/* double solve(int n, int m, int k, int h, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    // Create graph
    graph.clear();
    graph.resize(n);
    range(i, 0, m) {
        graph[x[i]].push_back({y[i], c[i]});
        graph[y[i]].push_back({x[i], c[i]});
    }

    if (graph[0].size() == 0) {
        return -1;
    }
    
    int res = 1e15;
    for (pair<int, int> p : graph[0]) {
        if (p.first == h) {
            res = min(res, p.second);
            continue;
        }

        int c = 0;
        if (arr[p.first] == 1) {
            c = p.second;
        }
        else if (arr[p.first] == 0) {
            c = 0;
        }
        else {
            c = p.second / 2;
        }

        for (pair<int, int> q : graph[p.first]) {
            if (q.first == h) {
                res = min(res, c + q.second);
            }
        }
    }

    if (res == 1e15) {
        return -1;
    }

    return res;
} */

/* vector<double> bfs(int n, vector<int> &arr) {
    // Setup priority queue for dijkstras
    vector<double> d(n, 1e15);
    queue<int> q;
    vector<bool> vis(n);

    arr[0] = 0;
    range(i, 0, n) {
        if (visited[i] and arr[i] == 0) {
            // print(i);
            q.push(i);
            d[i] = 0;
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (pair<int, int> p : graph[u]) {
            int v, w;
            tie(v, w) = p;
            if (!vis[v]) {
                vis[v] = true;
                d[v] = d[u] + w;
                // print(v, w, d[v]);
                q.push(v);
            }
        }
    }

    return d;
}

double solve(int n, int m, int k, int h, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    // Create graph
    graph.clear();
    graph.resize(n);
    range(i, 0, m) {
        graph[x[i]].push_back({y[i], c[i]});
        graph[y[i]].push_back({x[i], c[i]});
    }

    // Find adouble reachable nodes using dfs
    visited.clear();
    visited.resize(n);
    dfs(0);

    // Run dijkstras
    vector<double> d = bfs(n, arr);

    if (d[h] == 1e15) {
        return -1;
    }

    return d[h];
} */

double solve(int n, int m, int k, int h, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    set<int> s;
    for (int i = h - 1; i >= 0; i--) {
        if (arr[i] == 2) {
            s.insert(i);
            if ((int) s.size() == k) {
                break;
            }
        }
    }

    double res = 0;
    range(i, 0, h) {
        res += c[i];
        if (arr[i + 1] == 0) {
            res = 0;
        }
        else if (s.count(i + 1)) {
            res /= 2;
        }
    }

    return res;
}

// #include "stub.cpp"
