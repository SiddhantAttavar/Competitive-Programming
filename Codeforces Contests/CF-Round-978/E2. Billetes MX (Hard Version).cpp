#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define ll long long
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

int mod_pow(ll a, int b) {
    ll res = 1;
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

bool check(vector<pair<pair<int, int>, int>> &v, int n, int m) {
    vector<vector<pair<int, int>>> graph(n);
    vector<pair<int, int>> a(m, {-1, -1});
    for (pair<pair<int, int>, int> p : v) {
        int x, y;
        tie(x, y) = p.first;
        if (a[y].first != -1) {
            graph[x].push_back({a[y].first, a[y].second ^ p.second});
            graph[a[y].first].push_back({x, a[y].second ^ p.second});
        }
        a[y] = {x, p.second};
    }

    vector<int> c(n, -1);
    range(i, 0, n) {
        if (c[i] != -1) {
            continue;
        }
        c[i] = 0;
        if (!dfs(i, graph, c)) {
            return false;
        }
    }

    graph.clear();
    graph.resize(m);
    a.clear();
    a.resize(n, {-1, -1});
    for (pair<pair<int, int>, int> p : v) {
        int x, y;
        tie(x, y) = p.first;
        if (a[x].first != -1) {
            graph[y].push_back({a[x].first, a[x].second ^ p.second});
            graph[a[x].first].push_back({y, a[x].second ^ p.second});
        }
        a[x] = {y, p.second};
    }

    c.clear();
    c.resize(m, -1);
    range(i, 0, m) {
        if (c[i] != -1) {
            continue;
        }
        c[i] = 0;
        if (!dfs(i, graph, c)) {
            return false;
        }
    }

    return true;
}

ll combine(int x, int y) {
    return ((ll) x) << 30 | y;
}

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

        vector<pair<pair<int, int>, int>> w(q);
        range(i, 0, q) {
            int x, y, z;
            input(x, y, z);
            w[i] = {{x - 1, y - 1}, z};
        }

        if (!check(v, n, m)) {
            range(i, 0, q + 1) {
                print(0);
            }
            continue;
        }

        map<ll, int> hash;
        range(i, 0, k) {
            hash[combine(v[i].first.first, v[i].first.second)] = i;
        }
        range(i, 0, q) {
            hash[combine(w[i].first.first, w[i].first.second)] = i + k;
        }

        vector<int> a(n, -1), b(m, -1);
        DSU d(k + q);
        int s = 0, t = 0;
        int c = 0;
        for (pair<pair<int, int>, int> p : v) {
            int x, y;
            tie(x, y) = p.first;
            vector<pair<int, int>> l;
            if (a[x] != -1) {
                l.push_back({x, a[x]});
            }
            else {
                s++;
            }

            if (b[y] != -1) {
                l.push_back({b[y], y});
            }
            else {
                t++;
            }

            c++;
            for (pair<int, int> q : l) {
                ll u = hash[combine(x, y)];
                ll v = hash[combine(q.first, q.second)];
                c -= d.unite(u, v);
            }

            a[x] = y;
            b[y] = x;
        }

        print(mod_pow(2, 30 * (n - s + m - t + c - 1)));

        int l = 0, r = q - 1, res = -1;
        while (l <= r) {
            int k = (l + r) / 2;
            vector<pair<pair<int, int>, int>> u(v.begin(), v.end());
            u.insert(u.end(), w.begin(), w.begin() + k + 1);
            if (check(u, n, m)) {
                res = k;
                l = k + 1;
            }
            else {
                r = k - 1;
            }
        }

        range(j, 0, res + 1) {
            int x, y;
            tie(x, y) = w[j].first;
            vector<pair<int, int>> l;
            if (a[x] != -1) {
                l.push_back({x, a[x]});
            }
            else {
                s++;
            }

            if (b[y] != -1) {
                l.push_back({b[y], y});
            }
            else {
                t++;
            }

            c++;
            for (pair<int, int> q : l) {
                ll u = hash[combine(x, y)];
                ll v = hash[combine(q.first, q.second)];
                c -= d.unite(u, v);
            }

            a[x] = y;
            b[y] = x;

            print(mod_pow(2, 30 * (n - s + m - t + c - 1)));
        }
        range(i, res + 1, q) {
            print(0);
        }
    }
}
