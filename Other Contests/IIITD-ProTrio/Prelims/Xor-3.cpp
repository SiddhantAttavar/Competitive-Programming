#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int dfs1(int u, vector<set<int>> &graph, vector<bool> &vis) {
    vis[u] = true;
    int res = 1;
    for (int v : graph[u]) {
        if (!vis[v]) {
            res += dfs1(v, graph, vis);
        }
    }
    return res;
}

int dfs2(int u, vector<set<int>> &graph, set<int> &s) {
    // cout << u << endl;
    s.erase(u);
    int res = 1;
    set<int> t;
    for (int v : graph[u]) {
        if (s.count(v)) {
            s.erase(v);
            t.insert(v);
        }
    }
    swap(s, t);
    for (int  v : t) {
        res += dfs2(v, graph, s);
    }
    return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
        int q;
        input(q);

        int n, m;
        input(n, m);

        vector<set<int>> graph(n);
        range(i, 0, m) {
            int u, v;
            input(u, v);
            graph[u - 1].insert(v - 1);
            graph[v - 1].insert(u - 1);
        }

        vector<int> cc;
        if (q == 0) {
            vector<bool> v(n, false);

            range(i, 0, n) {
                if (!v[i]) {
                    cc.push_back(dfs1(i, graph, v));
                }
            }
        }
        else {
            // cout << "debug" << endl;
            set<int> s;
            range(i, 0, n) {
                s.insert(i);
            }
            range(i, 0, n) {
                if (s.count(i)) {
                    cc.push_back(dfs2(i, graph, s));
                }
            }
        }

        set<int> t = set<int>(cc.begin(), cc.end());

        // arrPrint(t);
        
        int x = 0;
        for (int i : cc) {
            x ^= i;
        }

        int res = x;

        for (int i : t) {
            res = max(res, x ^ i);
            for (int j : t) {
                res = max(res, x ^ i ^ j);
                for (int k : t) {
                    res = max(res, x ^ i ^ j ^ k);
                }
            }
        }

        print(res);
    }
}
