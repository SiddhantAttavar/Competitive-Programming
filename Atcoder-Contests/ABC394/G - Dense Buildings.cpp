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
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

struct DSU {
    vector<vector<pair<int, int>>> a;
    DSU(int n) {
        a.resize(n, {{-1e9, -1}});
    }

    int get(int x, int t) {
        int i = lower_bound(a[x].begin(), a[x].end(), make_pair(t, (int) 1e9)) - a[x].begin() - 1;
        // print(i, x, t, a[x][i].first, a[x][i].second);
        // for (pair<int, int> p : a[x]) {
        //     cout << p.first << ',' << p.second << ' '; 
        // }
        // cout << endl;
        // cout.flush();
        // assert(i >= 0);
        // assert(i < a[x].size());
        if (a[x][i].second < 0) {
            return x;
        }
        // return a[x][i].second = get(a[x][i].second, t);
        return get(a[x][i].second, t);
    }

    void put(int x, int k, int t) {
        a[x].push_back({t, k});
    }

    bool unite(int x, int y, int t) {
        x = get(x, t);
        y = get(y, t);

        if (x == y) {
            return false;
        }

        int p = (--lower_bound(a[x].begin(), a[x].end(), make_pair(t, 0ll)))->second;
        int q = (--lower_bound(a[y].begin(), a[y].end(), make_pair(t, 0ll)))->second;
        // print(p, q);
        // cout.flush();
        // assert(p < 0);
        // assert(q < 0);
        if (p > q) {
            swap(x, y);
        }

        put(x, p + q, t);
        put(y, x, t);
        return true;
    }
};

int32_t main() {
    setup();

    int n, m;
    input(n, m);

    vector<vector<int>> a(n, vector<int>(m));
    range(i, 0, n) {
        arrput(a[i]);
    }

    vector<pair<int, pair<int, int>>> v;
    range(i, 0, n) {
        range(j, 0, m) {
            v.push_back({-a[i][j], {i, j}});
        }
    }
    sort(v.begin(), v.end());

    DSU d(n * m);
    range(i, 1, v.size()) {
        int p, q;
        tie(p, q) = v[i].second;
        if (p > 0 and a[p - 1][q] >= a[p][q]) {
            d.unite(p * m + q, (p - 1) * m + q, -a[p][q]);
        }
        if (p < n - 1 and a[p + 1][q] >= a[p][q]) {
            d.unite(p * m + q, (p + 1) * m + q, -a[p][q]);
        }
        if (q > 0 and a[p][q - 1] >= a[p][q]) {
            d.unite(p * m + q, p * m + (q - 1), -a[p][q]);
        }
        if (q < m - 1 and a[p][q + 1] >= a[p][q]) {
            d.unite(p * m + q, p * m + (q + 1), -a[p][q]);
        }
    }
    // print("");
    // print(d.get(2, -3), d.get(5, -3));
    // return 0;

    int q;
    input(q);
    while (q--) {
        int i, j, x, k, l, y;
        input(i, j, x, k, l, y);

        i--;
        j--;
        k--;
        l--;

        int s = 1, e = min(x, y), res = 0;
        while (s <= e) {
            int t = (s + e) / 2;
            // print(i, j, t, k, l, 's');
            // cout.flush();
            if (d.get(i * m + j, -t) == d.get(k * m + l, -t)) {
                res = t;
                s = t + 1;
            }
            else {
                e = t - 1;
            }
        }
        print(x + y - 2 * res);
        cout.flush();
    }
}
