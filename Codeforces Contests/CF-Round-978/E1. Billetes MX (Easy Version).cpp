#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

bool dfs(int u, vector<vector<pair<int, int>>> &graph, vector<int> &c) {
    for (pair<int, int> p : graph[u]) {
        if (c[p.first] == -1) {
            c[p.first] = c[u] ^ p.second;
            if (!dfs(p.first, graph, c)) {
                return false;
            }
        }
        else if (c[p.first] != (c[u] ^ p.second)) {
            return false;
        }
    }
    return true;
}

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

struct DSU {
    vector<int> a;
    DSU(int n) {
        a.resize(n, -1);
    }
    int get(int x) {
        if (a[x] < 0) {
            return x;
        }
        return a[x] = get(a[x]);
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);

        if (x == y) {
            return false;
        }

        if (a[x] > a[y]) {
            swap(x, y);
        }
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m, k, q;
        input(n, m, k, q);

        vector<pair<pair<int, int>, int>> v(k);
        range(i, 0, k) {
            int x, y, z;
            input(x, y, z);
            v[i] = {{x - 1, y - 1}, z};
        }

        vector<vector<pair<int, int>>> a(n), b(m);
        for (pair<pair<int, int>, int> p : v) {
            a[p.first.first].push_back({p.first.second, p.second});
            b[p.first.second].push_back({p.first.first, p.second});
        }

        range(i, 0, n) {
            sort(a[i].begin(), a[i].end());
        }
        range(i, 0, m) {
            sort(b[i].begin(), b[i].end());
        }

        bool flag = true;
        vector<vector<pair<int, int>>> graph(n);
        range(j, 0, m) {
            range(k, 1, (int) b[j].size()) {
                int x = b[j][k - 1].second ^ b[j][k].second;
                graph[b[j][k - 1].first].push_back({b[j][k].first, x});
                graph[b[j][k].first].push_back({b[j][k - 1].first, x});
            }
        }

        vector<int> c(n, -1);
        range(j, 0, n) {
            if (c[j] != -1) {
                continue;
            }
            c[j] = 0;
            if (!dfs(j, graph, c)) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            print(0);
            continue;
        }

        graph.clear();
        graph.resize(m);
        range(j, 0, n) {
            range(k, 1, (int) a[j].size()) {
                int x = (a[j][k - 1].second ^ a[j][k].second);
                graph[a[j][k - 1].first].push_back({a[j][k].first, x});
                graph[a[j][k].first].push_back({a[j][k - 1].first, x});
            }
        }

        c.clear();
        c.resize(m);
        range(i, 0, m) {
            if (c[i] != -1) {
                continue;
            }
            c[i] = 0;
            if (!dfs(i, graph, c)) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            print(0);
            continue;
        }

        map<int, int> hash;
        range(i, 0, k) {
            hash[v[i].first.first << 30 | v[i].first.second] = i;
        }

        DSU d(k);
        range(i, 0ll, n) {
            range(j, 1, (int) a[i].size()) {
                int u = hash[i << 30 | a[i][j - 1].first];
                int v = hash[i << 30 | a[i][j].first];
                d.unite(u, v);
            }
        }
        range(i, 0ll, m) {
            range(j, 1, (int) b[i].size()) {
                int u = hash[b[i][j - 1].first << 30 | i];
                int v = hash[b[i][j].first << 30 | i];
                d.unite(u, v);
            }
        }

        vector<set<int>> s(k), t(k);
        range(i, 0, k) {
            int u = d.get(i);
            s[u].insert(v[i].first.first);
            t[u].insert(v[i].first.second);
        }

        int r = 0, p = 0, l = 0;
        range(i, 0, k) {
            if (!s[i].empty()) {
                r += s[i].size();
                p += t[i].size();
                l++;
            }
        }
        print(mod_pow(2, 30 * (n + m - r - p + l - 1)));
    }
}
