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
    int g, c, l;
    cin >> g >> c >> l;

    if (g > c) {
        swap(g, c);
    }
    if (c > l) {
        swap(c, l);
    }
    if (g > c) {
        swap(g, c);
    }

    if (l - g >= 10) {
        cout << "check again\n";
    }
    else {
        cout << "final " << c << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
