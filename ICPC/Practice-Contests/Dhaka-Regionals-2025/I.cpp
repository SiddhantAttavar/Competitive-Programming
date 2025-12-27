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

const int M = 1e9 + 7;
const int K = 26;

int mpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int mdiv(int a, int b) {
    return a * mpow(b, M - 2) % M;
}

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vi powk(n + 1, 1);
    rep(i, 0, n) {
        powk[i + 1] = powk[i] * K % M;
    }

    vi p(n + 1, 0), q(n + 1, 0);
    rep(i, 0, n) { 
        p[i + 1] = (p[i] + (a[i] - 'a') * powk[i]) % M;
        q[i + 1] = (q[i] + (b[i] - 'a') * powk[i]) % M;
    }

    map<int, int> m;
    rep(j, 0, n) {
        int x = mdiv((p[n] - p[j] + M) % M, powk[j]);
        int y = mdiv((q[n] - q[j] + M) % M, powk[j]);
        cout << x << ' ' << y << ' ' << (x - y + M) % M << endl;
        m[(x - y + M) % M]++;
    }
    // for (auto [k, v] : m) {
    //     cout << k << ' ' << v << endl;
    // }

    int res = 0;
    rep(i, 0, n) {
        int x = p[i + 1], y = q[i + 1];
        cout << x << ' ' << y << ' ' << (x - y + M) % M << endl;
        res += m[(x - y + M) % M];
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}

