#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<unordered_set<int>> graph;
vector<bool> visited;
int n;

void init(int N, int s, vi t, vector<vi> a, vector<vi> b) {
    n = N;

    // Store all the timings
    vector<pair<int, pair<int, int>>> l;
    range(i, 0, n) {
        range(j, 0, t[i]) {
            l.push_back({i, {a[i][j], b[i][j]}});
        }
    }

    // Build the graph
    graph.clear();
    graph.resize(n);

    range(i, 0, l.size()) {
        range(j, i + 1, l.size()) {
            if (l[i].second.first <= l[j].second.second and l[j].second.first <= l[i].second.second) {
                graph[l[i].first].insert(l[j].first);
                graph[l[j].first].insert(l[i].first);
            }
        }
    }
}

int dfs(int u, int d) {
    if (d == 0) {
        return 0;
    }

    visited[u] = true;
    int res = 1;
    for (int v : graph[u]) {
        if (!visited[v]) {
            res += dfs(v, d - 1);
        }
    }

    return res;
}

int count_users(int u) {
    visited.clear();
    visited.resize(n, false);
    return dfs(u, n);
}

/*vi t = {2, 1, 1, 1, 1};
vector<vi> a = {{2, 7}, {1}, {1}, {9}, {5}};
vector<vi> b = {{4, 9}, {3}, {1}, {10}, {6}};

int main() {
    init(5, 10, t, a, b);
    print(count_users(0));
}*/