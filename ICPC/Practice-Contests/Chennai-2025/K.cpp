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

const int N = 2e5;
vi spf(N + 1);

void solve() {
	int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << (n == 1) << endl;
        return;
    }

    map<int, int> m;
    n /= 2;
    while (n > 1) {
        m[spf[n]]++;
        n /= spf[n];
    }
    int x = 1;
    for (auto [k, v] : m) {
        x *= v + 1;
    }
    cout << x << endl;
}

signed main() {
    iota(all(spf), 0);
    rep(i, 2, N + 1) {
        if (spf[i] != i) {
            continue;
        }
        for (int j = i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
