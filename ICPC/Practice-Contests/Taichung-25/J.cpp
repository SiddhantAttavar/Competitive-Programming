#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

        if (a[x] < a[y]) {
            swap(x, y);
        }

        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1), h(n + 1);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    rep(i, 0, n - 1) {
        int x;
        cin >> x;
        h[x].push_back(i);
    }
    
    vector<int> p(n + 1);
    p[0] = n;
    vector<int> x(n, 1), r(n);
    rep(i, 0, n) {
        r[i] = i;
    }
    DSU d(n);
    rep(k, 0, n) {
        int y = n - k;
        for (int i : h[k]) {
            int s = r[d.get(i)], t = r[d.get(i + 1)];
            p[s - x[s] + 1] -= y;
            p[s + 1] += y;
            p[t - x[t] + 1] -= y;
            p[t + 1] += y;

            d.unite(s, t);
            x[t] += x[s];
            r[d.get(s)] = t;
            p[t - x[t] + 1] += y;
            p[t + 1] -= y;
        }

        for (int i : a[k]) {
            int j = r[d.get(i)];
            p[j - x[j] + 1] -= y;
            p[j - x[j] + 2] += y;
            x[j]--;
        }

        // int x = 0;
        // rep(i, 0, n) {
        //     x += p[i];
        //     cout << x << ' ';
        // }
        // cout << endl;
    }
    
    rep(i, 0, n) {
        p[i + 1] += p[i];
    }
    rep(i, 0, n) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
