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

#define yay {cout << "YES" << endl; continue; }
#define meh {cout << "NO" << endl; continue; }

void solve() {
	int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> p(2 * n, 0);
    rep(i, 0, 2 * n - 1) {
        p[i + 1] = p[i] + (s[i] == 'W');
    }

    int x = 0;
    rep(i, 0, n) {
        x = max(x, p[i + n] - p[i]);
    }
    cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
