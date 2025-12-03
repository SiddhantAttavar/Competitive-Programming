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

vector<bool> get(int w, int wa, int xa, int da, int wb, int xb, int db) {
    int p = 2 * (w - wa) * (w - wb);
    vector<bool> res(p);
    rep(i, 0, p) {
        res[i] = (xa <= xb and xb < xa + wa) or (xb <= xa and xa < xb + wb);

        xa += da;
        xb += db;
        if (xa < 0 or xa + wa > w) {
            da = -da;
            xa += 2 * da;
        }
        if (xb < 0 or xb + wb > w) {
            db = -db;
            xb += 2 * db;
        }
    }
    return res;
}

void solve() {
	int w, h;
    cin >> w >> h;

    int wa, ha, xa, ya, dxa, dya;
    cin >> wa >> ha >> xa >> ya >> dxa >> dya;
    
    int wb, hb, xb, yb, dxb, dyb;
    cin >> wb >> hb >> xb >> yb >> dxb >> dyb;

    int p = 2 * lcm(w - wa, w - wb), q = 2 * lcm(h - ha, h - hb);
    vector<bool> a = get(w, wa, xa, dxa, wb, xb, dxb);
    vector<bool> b = get(h, ha, ya, dya, hb, yb, dyb);

    int g = gcd(p, q);
    vector<int> s(g, 0);
    rep(i, 0, q) {
        s[i % g] += b[i];
    }

    int n = 0, d = p * q;
    rep(x, 0, p) {
        if (a[x]) {
            n += g * s[x % g];
        }
    }
    
    int t = gcd(n, d);
    cout << (n / t) << '/' << (d / t) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
