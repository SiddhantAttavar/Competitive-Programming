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
    const int N = 1e7;
    vi spf(N + 1), p;
    iota(all(spf), 0);
    rep(i, 2, N + 1) {
        if (spf[i] != i) {
            continue;
        }
        p.push_back(i);
        for (int j = i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    string s;
    cin >> s;

    int n = sz(s), k = 0;
    if (n >= 18) {
        s = s.substr(0, 14);
        k = n - 14;
    }

    int x = stoll(s);
    map<int, int> m;
    for (int i : p) {
        while (x % i == 0) {
            m[i]++;
            x /= i;
        }
    }
    if (x != 1) {
        m[x] = 1;
        x = 1;
    }
    if (k) {
        m[2] += k;
        m[5] += k;
    }

    cout << sz(m) << endl;
    for (auto [p, e] : m) {
        cout << p << ' ' << e << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
