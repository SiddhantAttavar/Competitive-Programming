#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

int h = 30;

void insert(int x, vector<pair<int, int>> &tree, vector<int> &s) {
    int u = 0;
    for (int i = h - 1; i >= 0; i--) {
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

int query(int x, int z, vector<pair<int, int>> &tree, vector<int> &s) {
    int u = 0, res = 0;
    for (int i = h - 1; i >= 0; i--) {
        if (z >> i & 1) {
            if ((x >> i & 1) and tree[u].first != -1) {
                res += s[tree[u].first];
            }
            else if (!(x >> i & 1) and tree[u].second != -1) {
                res += s[tree[u].second];
            }
            x ^= 1 << i;
        }
        if (x >> i & 1) {
            u = tree[u].first;
        }
        else {
            u = tree[u].second;
        }
        if (u == -1) {
            return res;
        }
    }
    return res + s[u];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    int z = (1 << h) - 1;
    sort(a.begin(), a.end());
    rep(i, 1, n) {
        z = min(z, a[i - 1] ^ a[i]);
    }

    vector<pair<int, int>> tree = {{-1, -1}};
    vector<int> s = {0};
    tree.reserve(2 * n);
    s.reserve(2 * n);
    int res = 0;
    rep(i, 0, m) {
        int x;
        cin >> x;
        res += query(x, z, tree, s);
        insert(x, tree, s);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
