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
	int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> a(n);
    vector<int> l(m);
    rep(i, 0, n) {
        cin >> a[i][0];
    }
    rep(i, 0, n) {
        cin >> a[i][1];
    }
    rep(i, 0, m) {
        cin >> l[i];
    }
    sort(a.begin(), a.end(), [](array<int, 3> x, array<int, 3> y) {
        return x[1] < y[1];
    });

    int c = 1e18;
    for (int i = n - 1; i >= 0; i--) {
        a[i][2] = min(c, a[i][1]) - a[i][0];
        c = a[i][2];
    }
    
    int j = 0;
    c = 0;
    vector<int> v(m);
    rep(i, 0, m) {
        while (j < n and c + l[i] > a[j][2]) {
            c += a[j][0];
            j++;
        }
        c += l[i];
        v[i] = c;
    }

    while (q--) {
        int t;
        cin >> t;
        cout << upper_bound(v.begin(), v.end(), t) - v.begin() << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
