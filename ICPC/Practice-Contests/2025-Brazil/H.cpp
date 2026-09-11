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
    int n, k;
	cin >> n >> k;

	vi a(1 << k, 0);
	rep(i, 0, n) {
		string s;
		cin >> s;
		int x = 0;
		rep(j, 0, k) {
			x |= (s[j] == '1') << j;
		}
		a[x]++;
	}
	
	rep(i, 0, k) {
		rep(j, 0, 1 << k) {
			if (j >> i & 1) {
				a[j] += a[j ^ (1 << i)];
			}
		}
	}
	rep(j, 0, 1 << k) {
		a[j] = a[j] * (a[j] - 1) * (a[j] - 2) / 6;
	}
	rep(i, 0, k) {
		for (int j = (1 << k) - 1; j >= 0; j--) {
			if (j >> i & 1) {
				a[j] -= a[j ^ (1 << i)];
			}
		}
	}

	int m;
	cin >> m;
	rep(i, 0, m) {
		string s;
		cin >> s;
		int x = 0;
		rep(j, 0, k) {
			x |= (s[j] == '1') << j;
		}
		cout << a[x] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
