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

    int a = n, b = n;
    int res = (n + 1) / 2;
    if (n % 2) {
        a--;
    }

    while (a > 0 or b > 0) {
        res++;
        a -= 2;
        b--;
        if (a < 0) {
            b += a;
            a = 0;
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
