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
    string s;
    cin >> s;

    string a = s.substr(0, sz(s) / 2), b = s.substr(sz(s) / 2);
    int x = 0, y = 0;
    for (char c : a) {
        x += c - 'A';
    }
    for (char c : b) {
        y += c - 'A';
    }
    
    x %= 26;
    rep(i, 0, sz(a)) {
        a[i] = (a[i] - 'A' + x) % 26 + 'A';
    }
    y %= 26;
    rep(i, 0, sz(b)) {
        b[i] = (b[i] - 'A' + y) % 26 + 'A';
    }

    rep(i, 0, sz(a)) {
        a[i] = (a[i] - 'A' + b[i] - 'A') % 26 + 'A';
    }
    cout << a << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
