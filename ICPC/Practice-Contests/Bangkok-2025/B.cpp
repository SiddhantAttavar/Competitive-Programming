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

    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n == 2) {
        if (m % 2) {
            cout << "2 1\n";
        }
        else {
            cout << "1 2\n";
        }
        return;
    }

    m = min(m, n);
    rep(i, 0, m) {
        cout << n - i << ' ';
    }
    rep(i, 0, n - m) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
