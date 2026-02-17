#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int r, c;
    cin >> r >> c;

    vi a(r * c, false), b(r * c, false);
    int x = -1, y = -1, z = -1;
    rep(i, 0, r) {
        string s;
        cin >> s;
        rep(j, 0, c) {
            if (s[j] == 'X') {
                a[i * c + j] = true;
            }
            else if (s[j] == 'S') {
                x = i * c + j;
            }
        }
    }
    rep(i, 0, r) {
        string s;
        cin >> s;
        rep(j, 0, c) {
            if (s[j] == 'X') {
                b[i * c + j] = true;
            }
            else if (s[j] == 'S') {
                y = i * c + j;
            }
            else if (s[j] == 'D') {
                z = i * c + j;
            }
        }
    }

    int k = r * c;
    vi d(k * k, -1);
    queue<int> qu;
    d[x * k + y] = 0;
    qu.push(x * k + y);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        int s = u / k, t = u % k;
        if (t == z) {
            cout << d[u] << endl;
            return;
        }

        int x = s / c, y = s % c, p = t / c, q = t % c;
        vector<array<int, 4>> l = {
            {x - 1, y, p - 1, q},
            {x + 1, y, p + 1, q},
            {x, y - 1, p, q - 1},
            {x, y + 1, p, q + 1}
        };
        for (auto [x, y, p, q] : l) {
            if (min(x, y) < 0 or x >= r or y >= c) {
                continue;
            }
            int ns = x * c + y, nt = p * c + q;
            if (a[ns]) {
                continue;
            }
            int v = ns * k + nt;
            if (min(p, q) < 0 or p >= r or q >= c or b[nt]) {
                v = ns * k + t;
            }
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
