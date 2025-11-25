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

const int N = 1e6;

void get(string &s, vector<int> &res) {
    rep(i, 0, sz(s)) {
        if (s[i] == '+' or s[i] == '*') {
            continue;
        }
        int a = 0, b = 1, c = s[i] - '0';
        rep(j, i + 1, sz(s)) {
            if (s[j] == '+') {
                if (c == 0) {
                    break;
                }
                a = a + b * c;
                b = 1;
                c = 0;
            }
            else if (s[j] == '*') {
                if (c == 0) {
                    break;
                }
                b = b * c;
                c = 0;
            }
            else {
                c = 10 * c + (s[j] - '0');
                if (a + b * c > N) {
                    break;
                }
                res[a + b * c]++;
            }
        }
    }
}

void calc(string &s, vector<int> &res) {
    get(s, res);
    reverse(s.begin(), s.end());
    get(s, res);
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> res(N + 1);
    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vector<string> b(m, string(n, '+'));    
    vector<string> x(n + m - 1), y(n + m - 1);
    rep(i, 0, n) {
        rep(j, 0, m) {
            x[i + j] += a[i][j];
            y[i + m - 1 - j] += a[i][j];
            b[j][i] = a[i][j];
            if (a[i][j] != '+' and a[i][j] != '*') {
                res[a[i][j] - '0']++;
            }
        }
    }

    rep(i, 0, n) {
        calc(a[i], res);
    }
    rep(j, 0, m) {
        calc(b[j], res);
    }
    rep(i, 0, n + m - 1) {
        calc(x[i], res);
        calc(y[i], res);
    }

    while (q--) {
        int x;
        cin >> x;
        cout << res[x] << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
