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
    int n, m;
    cin >> n >> m;

    vi tot(26, 0);
    vector<vi> a(n, vi(26, 0));
    rep(i, 0, n) {
        string s;
        cin >> s;
        for (char c : s) {
            a[i][c - 'A']++;
            tot[c - 'A']++;
        }
    }

    rep(i, 0, n) {
        vi cur = tot;
        rep(j, 0, 26) {
            cur[j] -= a[i][j];
        }

        vi temp = cur;
        rep(j, 0, 26) {
            temp[j] *= m;
            temp[j] -= a[i][j];
        }

        if (*min_element(all(temp)) < 0) {
            cout << -1 << ' ';
            continue;
        }

        int k = m;
        rep(j, 0, 26) {
            if (cur[j] > 0) {
                k = min(k, temp[j] / cur[j]);
            }
        }
        cout << k << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
