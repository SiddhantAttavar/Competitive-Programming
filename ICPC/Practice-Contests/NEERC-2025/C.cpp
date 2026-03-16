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
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vi v;
    while (n) {
        v.push_back((n & ((1ll << 7) - 1)) | (1ll << 7));
        n >>= 7;
    }
    reverse(all(v));
    v.back() ^= 1ll << 7;
    for (int i : v) {
        cout << i << ' ';
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
