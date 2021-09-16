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

unordered_map<ll, ll> memo;
vector<vector<pair<int, int>>> graph;

ll combine(int a, int b, int c) {
    return 2000 * (2000ll * a + b) + c;
}

ll solve(int u, int par, int k, int m) {
    if (k == -1) {
        return -1;
    }

    ll key = combine(u, k, m);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    vector<pair<ll, ll>> fin;
    for (pair<int, int> p : graph[u]) {
        if (p.first != par) {
            fin.push_back({solve(p.first, u, m - 1, m), solve(p.first, u, m, m) + p.second});
        }
    }

    sort(fin.begin(), fin.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.first - a.second) < (b.first - b.second);
    });
    ll res = 0;
    range(i, 0, min(k, (int) fin.size())) {
        res += min(fin[i].first, fin[i].second);
    }
    range(i, min(k, (int) fin.size()), fin.size()) {
        res += fin[i].second;
    }

    return memo[key] = res;
}

vector<ll> minimum_closure_costs(int n, vi u, vi v, vi w) {
    memo.clear();
    vector<ll> res(n, 0);
    graph.clear();
    graph.resize(n);
    range(i, 0, n - 1) {
        graph[u[i]].push_back({v[i], w[i]});
        graph[v[i]].push_back({u[i], w[i]});
    }
    int l = 0;
    range(i, 0, n) {
        l = max(l, (int) graph[i].size());
    }
    range(i, 0, l) {
        res[i] = solve(0, -1, i, i);
    }
    return res;
}

/*int main() {
    setup();
    int n; input(n);
    vi u(n - 1), v(n - 1), w(n - 1);
    range(i, 0, n - 1) {
        input(u[i], v[i], w[i]);
    }
    arrPrint(minimum_closure_costs(n, u, v, w));
}*/