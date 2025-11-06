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

int get(vector<int> &v) {
    pair<int, int> res = {1e18, -1};
    int a = 0, b = accumulate(v.begin(), v.end(), 0ll), p = 0, q = v.size();
    for (int i : v) {
        p++;
        a += i;
        q--;
        b -= i;
        res = min(res, make_pair(i * p - a + b - i * q, i));
    }
    return res.second;
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << get(x) << ' ' << get(y) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
