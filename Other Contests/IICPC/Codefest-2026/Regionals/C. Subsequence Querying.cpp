#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;

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

bool debug = false;
int K = 5000;
vi A;

bool query(vi &b) {
	assert(K--);
	if (debug) {
		assert(*max_element(all(b)) < sz(A));
		assert(*min_element(all(b)) >= 0);
		assert(sz(b) <= sz(A));
	}
	if (debug) {
		int j = 0;
		for (int i : A) {
			if (j < sz(b) and b[j] == i) {
				j++;
			}
		}
		return j == sz(b);
	}

	cout << "? " << sz(b);
	for (int i : b) {
		cout << ' ' << i + 1;
	}
	cout << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n;
	cin >> n;

	K = 5000;
	if (debug) {
		A.resize(n);
		rep(i, 0, n) {
			cin >> A[i];
			A[i]--;
		}
	}

	vi f(n, 0);
	rep(i, 0, n) {
		while (f[i] < n) {
			vi x(f[i] + 1, i);
			if (query(x)) {
				f[i]++;
			}
			else {
				break;
			}
		}
	}

	vi res;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (!f[j]) {
				continue;
			}
			bool flag = true;
			rep(k, 0, n) {
				if (!f[k] or k == j) {
					continue;
				}
				vi x = res;
				x.push_back(j);
				rep(l, 0, f[k]) {
					x.push_back(k);
				}
				if (!query(x)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res.push_back(j);
				f[j]--;
				break;
			}
		}
	}

	cout << '!';
	for (int i : res) {
		cout << ' ' <<  i + 1;
	}
	cout << endl;
	cout.flush();

	if (debug) {
		assert(res == A);
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
}
