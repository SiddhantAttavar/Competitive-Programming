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

const int MOD = 998244353;
int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

void solve() {
	int n;
	cin >> n;

	vi pow10(n + 3, 1);
	rep(i, 1, n + 3) {
		pow10[i] = pow10[i - 1] * 10 % MOD; 
	}

	string a;
	cin >> a;

	int s = 0;
	multiset<int> m;
	rep(i, 0, n) {
		s = (s + (a[i] - '0')) % 9;
		if (a[i] != '0') {
			m.insert(i);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int i, d;
		cin >> i >> d;

		i = n - i;
		s = (s - (a[i] - '0') + 9) % 9;
		if (a[i] != '0') {
			m.erase(i);
		}
		
		a[i] = d + '0';
		s = (s + (a[i] - '0')) % 9;
		if (a[i] != '0') {
			m.insert(i);
		}

		if (m.empty()) {
			cout << 0 << endl;
			continue;
		}

		int t = n - *m.rbegin() - 1;
		if (t == 0 and sz(m) == 1) {
			cout << (a[n - 1] == '9') << endl;
			continue;
		}

		int res = mdiv((pow10[t + 1] + MOD - 1) % MOD, 9);
		if (s == 0) {
			cout << res * 2 % MOD << endl;
		}
		else {
			cout << res << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
