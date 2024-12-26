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

        vector<set<pair<int, int>>> a(n), b(m);
        for (pair<pair<int, int>, int> p : v) {
            a[p.first.first].insert({p.first.second, p.second});
            b[p.first.second].insert({p.first.first, p.second});
        }

        bool flag = true;
        vector<vector<pair<int, int>>> graph1(n);
        range(j, 0, m) {
            if (b[j].empty()) {
                continue;
            }
            set<pair<int, int>>::iterator i = b[j].begin();
            while (next(i) != b[j].end()) {
                set<pair<int, int>>::iterator k = next(i);
                int x = i->second ^ k->second;
                graph1[i->first].push_back({k->first, x});
                graph1[k->first].push_back({i->first, x});
                i++;
            }
        }

        vector<int> c1(n, -1);
        range(j, 0, n) {
            if (c1[j] != -1) {
                continue;
            }
            c1[j] = 0;
            if (!dfs(j, graph1, c1)) {
                flag = false;
                break;
            }
        }

        vector<vector<pair<int, int>>> graph2(m);
        range(j, 0, n) {
            if (a[j].empty()) {
                continue;
            }
            set<pair<int, int>>::iterator i = a[j].begin();
            while (next(i) != a[j].end()) {
                set<pair<int, int>>::iterator k = next(i);
                int x = i->second ^ k->second;
                graph2[i->first].push_back({k->first, x});
                graph2[k->first].push_back({i->first, x});
                i++;
            }
        }

        vector<int> c2(m, -1);
        range(i, 0, m) {
            if (c2[i] != -1) {
                continue;
            }
            c2[i] = 0;
            if (!dfs(i, graph2, c2)) {
                flag = false;
                break;
            }
        }

        map<int, int> hash;
        range(i, 0, k) {
            hash[v[i].first.first << 30 | v[i].first.second] = i;
        }

        DSU d(k + q);
        range(i, 0ll, n) {
            if (a[i].empty()) {
                continue;
            }
            set<pair<int, int>>::iterator j = a[i].begin();
            while (next(j) != a[i].end()) {
                int u = hash[i << 30 | j->first];
                j++;
                int v = hash[i << 30 | j->first];
                d.unite(u, v);
            }
        }
        range(i, 0ll, m) {
            if (b[i].empty()) {
                continue;
            }
            set<pair<int, int>>::iterator j = b[i].begin();
            while (next(j) != b[i].end()) {
                int u = hash[j->first << 30 | i];
                j++;
                int v = hash[j->first << 30 | i];
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

        if (flag) {
            print(mod_pow(2, 30 * (n + m - r - p + l - 1)));
        }
        else {
            print(0);
        }

        vector<pair<pair<int, int>, int>> w(q);
        range(i, 0, q) {
            int x, y, z;
            input(x, y, z);
            w[i] = {{x - 1, y - 1}, z};
        }

        if (!flag) {
            range(i, 0, q) {
                print(0);
            }
            continue;
        }

        l = 0, r = q - 1;
        int res = q;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<pair<int, int>> u(v.begin(), v.end());
            u.insert(u.end(), w.begin(), w.begin() + m + 1);
            if (check(u)) {
                l = m + 1;
            }
            else {
                res = m;
                r = m - 1;
            }
        }

        range(i, k, k + q) {
            int x, y, z;
            input(x, y, z);
            x--;
            y--;

            if (!flag) {
                print(0);
                continue;
            }

            hash[x << 30 | y] = i;

            vector<pair<int, int>> v;
            set<pair<int, int>>::iterator j = a[x].lower_bound({y, 0});
            if (j != a[x].begin()) {
                v.push_back({x, prev(j)->first});
            }
            if (j != a[x].end()) {
                v.push_back({x, j->first});
            }

            j = b[y].lower_bound({x, 0});
            if (j != b[y].begin()) {
                v.push_back({prev(j)->first, y});
            }
            if (j != b[y].end()) {
                v.push_back({j->first, y});
            }

            print(mod_pow(2, 30 * (n + m - r - p + l - 1)));
        }
    }
}
