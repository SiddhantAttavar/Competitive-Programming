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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup();

    int n;
    input(n);

    vector<int> w(n);
    arrput(w);

    vector<pair<int, int>> a(n);
    rep(i, 0, n) {
        input(a[i].first, a[i].second);
        a[i] = {a[i].first - 1, a[i].second - 1};
    }

    vector<int> b(n);
    rep(i, 0, n) {
        b[i] = i;
    }
    sort(b.begin(), b.end(), [&](int x, int y) {
        return a[x].first > a[y].first;
    });

    vector<int> x(2 * n, 1e18), y(2 * n, 1e18);
    for (int i : b) {
        x[a[i].first] = min(x[a[i].first], w[i]);
    }
    for (int i = 2 * n - 2; i >= 0; i--) {
        x[i] = min(x[i], x[i + 1]);
    }

    sort(b.begin(), b.end(), [&](int x, int y) {
        return a[x].second < a[y].second;
    });
    for (int i : b) {
        y[a[i].second] = min(y[a[i].second], w[i]);
    }
    rep(i, 1, 2 * n) {
        y[i] = min(y[i], y[i - 1]);
    }

    int q;
    input(q);
    while (q--) {
        int s, t;
        input(s, t);

        s--;
        t--;

        if (a[s].first > a[t].first) {
            swap(s, t);
        }

        if (a[s].second < a[t].first) {
            print(w[s] + w[t]);
            continue;
        }

        int res = 1e18;
        if (max(a[t].second, a[s].second) < 2 * n - 1) {
            res = min(res, w[s] + w[t] + x[max(a[t].second, a[s].second)  + 1]);
        }
        if (a[s].first > 0) {
            res = min(res, w[s] + w[t] + y[a[s].first - 1]);
        }
        if (a[t].first > 0 and a[s].second < 2 * n - 1) {
            res = min(res, w[s] + w[t] + x[a[s].second + 1] + y[a[t].first - 1]);
        }

        if (res == 1e18) {
            print(-1);
        }
        else {
            print(res);
        }
    }
}
