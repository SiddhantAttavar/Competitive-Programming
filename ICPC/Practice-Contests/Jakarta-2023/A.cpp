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

void solve() {
	vector<string> v(3);
    cin >> v[0] >> v[1] >> v[2];

    string s = v[0] + v[1] + v[2];
    string res = "XXX";
    rep(i, 0, 9) {
        rep(j, 0, 9) {
            if (i == j or abs(i % 3 - j % 3) > 1 or abs(i / 3 - j / 3) > 1) {
                continue;
            }
            rep(k, 0, 9) {
                if (k == j or i == k or abs(k % 3 - j % 3) > 1 or abs(k / 3 - j / 3) > 1) {
                    continue;
                }
                res = min(res, string(1, s[i]) + s[j] + s[k]);
            }
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
