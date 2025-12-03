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

    string s, t;
    cin >> s >> t;

    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    a[0] = 1;
    a[1] = s[0] == t[0];
    b[1] = s[0] == '#' and t[0] == '.';
    c[1] = s[0] == '.' and t[0] == '#';
    rep(i, 0, n) {
        if (s[i] == '.') {
            if (t[i] == '.') {
                if (i > 0 and s[i - 1] == '.' and t[i - 1] == '.') {
                    a[i + 1] = min(2ll, a[i] + a[i - 1]);
                }
                else {
                    a[i + 1] = a[i];
                }
                b[i + 1] = c[i];
                c[i + 1] = b[i];
            }
            else {
                a[i + 1] = c[i];
                c[i + 1] = a[i];
            }
        }
        else {
            if (t[i] == '.') {
                a[i + 1] = b[i];
                b[i + 1] = a[i];
            }
            else {
                a[i + 1] = a[i];
            }
        }
    }
    // rep(i, 0, n + 1) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, n + 1) {
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, n + 1) {
    //     cout << c[i] << ' ';
    // }
    // cout << endl;

    if (a[n] == 0) {
        cout << "None\n";
    }
    else if (a[n] == 1) {
        cout << "Unique\n";
    }
    else {
        cout << "Multiple\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
