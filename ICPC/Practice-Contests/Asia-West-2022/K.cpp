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
    int n, d;
    cin >> n >> d;

    vector<int> l = {0, d, d << 6, d << 12, d | d << 6, d | d << 12};
    rep(i, 0, n) {
        rep(j, 0, 6) {
            cout << l[j] << ' ';
        }
        cout << endl;
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
