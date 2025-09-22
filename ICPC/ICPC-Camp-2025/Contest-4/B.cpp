#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 998244353;

void insert(int x, vector<pair<int, int>> &tree, vector<int> &s) {
    int u = 0;
    for (int i = 59; i >= 0; i--) {
        if (x >> i & 1) {
            if (tree[u].first == -1) {
                tree[u].first = tree.size();
                tree.push_back({-1, -1});
                s.push_back(0);
            }
            u = tree[u].first;
        }
        else {
            if (tree[u].second == -1) {
                tree[u].second = tree.size();
                tree.push_back({-1, -1});
                s.push_back(0);
            }
            u = tree[u].second;
        }
        s[u]++;
    }
}

int get(int x, int y, vector<pair<int, int>> &tree, vector<int> &s) {
    int u = 0, res = 0;
    for (int i = 59; i >= 0; i--) {
        if (y >> i & 1) {
            u = (x >> i & 1) ? tree[u].second : tree[u].first;
        }
        else if (x >> i & 1) {
            res += tree[u].second == -1 ? 0 : s[tree[u].second];
            u = tree[u].first;
        }
        else {
            res += tree[u].first == -1 ? 0 : s[tree[u].first];
            u = tree[u].second;
        }
        if (u == -1) {
            return res;
        }
    }
    return res + s[u];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    if (x == 0) {
        int res = 1;
        rep(i, 0, n) {
            res = res * 2 % MOD;
        }
        cout << (res + MOD - 1) % MOD << endl;
        return 0;
    }

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    int z = 63 - __builtin_clzll(x);
    int mask = (1ll << (z + 1)) - 1;

    map<int, vector<int>> m;
    for (int i : a) {
        m[i & ~mask].push_back(i & mask);
    }

    int res = 1;
    for (auto [_, v] : m) {
        int c = 1 + v.size();
        vector<pair<int, int>> tree = {{-1, -1}};
        vector<int> s = {0};
        for (int i : v) {
            if (i >> z & 1) {
                insert(i, tree, s);
            }
        }
        for (int i : v) {
            if (!(i >> z & 1)) {
                c += get(i, x, tree, s);
            }
        }
        c %= MOD;
        res = res * c % MOD;
    }
    cout << (res + MOD - 1) % MOD << endl;
}
