#include <bits/stdc++.h>
#include <bits/extc++.h> /// include-line, keep-include
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool debug = false;
vi graph[1000];

vi query(vi v) {
    if (debug) {
        vi res(sz(v), 0);
        rep(i, 0, sz(v)) {
            for (int j : graph[i]) {
                res[i] += v[j];
            }
            // cout << v[i] << ' ';
        }
        // cout << endl;
        return res;
    }

    cout << '?';
    for (int i : v) {
        cout << ' ' << i;
    }
    cout << endl;
    cout.flush();

    vi res(sz(v));
    rep(i, 0, sz(v)) {
        cin >> res[i];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    if (debug) {
        int m;
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
    }

    vi a(n, 1), b(n);
    rep(i, 0, n) {
        b[i] = i;
    }
    vi x = query(a), y = query(b);

    queue<int> q;
    rep(i, 0, n) {
        if (x[i] == 1) {
            q.push(i);
        }
    }

    vector<pii> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (x[u] != 1) {
            continue;
        }
        
        int v = y[u];
        res.push_back({u, v});
        
        x[u]--;
        y[u] = 0;

        x[v]--;
        y[v] -= u;
        if (x[v] == 1) {
            q.push(v);
        } 
    }

    cout << "! " << sz(res) << endl;
    for (auto [u, v] : res) {
        cout << u + 1 << ' ' << v + 1 << endl;
    }
    cout.flush();
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
