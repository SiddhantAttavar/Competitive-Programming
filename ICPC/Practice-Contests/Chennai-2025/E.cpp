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
	int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(all(a));
    a.push_back(1e18);

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        int l = 0, r = a[i + 1], x = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            int i = lower_bound(a.begin(), a.end(), m) - a.begin();
            if (m - i <= k) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        int j = lower_bound(a.begin(), a.end(), x) - a.begin();
        res += x - j + 1;
        k--;
        if (k < 0) {
            break;
        }
    }
    res += min(k + 1, a[0] + 1);
    res %= 998244353;
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
