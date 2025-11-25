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

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    a.insert(a.begin(), 0);
    a.push_back(1440);
    n += 2;

    int res = 0;
    rep(i, 1, n) {
        res += (a[i] - a[i - 1]) / 120;
    }
    
    if (res >= 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
