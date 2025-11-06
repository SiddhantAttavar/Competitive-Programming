#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n"

void solve() {
    string s;
    cin >> s;

    int res = 0;
    rep(i, 0, s.size() - 3) {
        res += s.substr(i, 4) == "kick";
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
