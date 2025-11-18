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
	int n;
    cin >> n;

    int x = 0;
    rep(i, 0, n) {
        char c;
        int y;
        cin >> c >> y;

        if (c == 'P') {
            x += y;
            continue;
        }
        
        if (y >= x + 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        x = max(0ll, x - y);
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
