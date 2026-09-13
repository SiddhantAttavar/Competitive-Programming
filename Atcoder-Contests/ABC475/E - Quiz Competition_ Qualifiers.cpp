#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

const int K = 200;

bitset<K> read() {
	string s;
	cin >> s;
	bitset<K> b = 0;
	rep(i, 0, sz(s)) {
		b[i] = s[i] == 'o';
	}
	return b;
}

void upd(bitset<K> b, vi &l, vi &r, vi &x, int c, int k) {
	int u = 0;
	rep(i, 0, k) {
		x[u] += c;
		if (b[i]) {
			if (r[u] == -1) {
				r[u] = sz(r);
				l.push_back(-1);
				r.push_back(-1);
				x.push_back(0);
			}
			u = r[u];
		}
		else {
			if (l[u] == -1) {
				l[u] = sz(l);
				l.push_back(-1);
				r.push_back(-1);
				x.push_back(0);
			}
			u = l[u];
		}
	}
	x[u] += c;
}

bool get(bitset<K> b, vi &l, vi &r, vi &x, int m, int k) {
	int u = 0;
	rep(i, 0, k) {
		if (l[u] == -1 or m >= x[l[u]]) {
			if (!b[i]) {
				return true;
			}
			if (l[u] != -1) {
				m -= x[l[u]];
			}
			u = r[u];
		}
		else {
			if (b[i]) {
				return false;
			}
			u = l[u];
		}
		if (u == -1) {
			break;
		}
	}
	return false;
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	bitset<K> t = read();
	vector<bitset<K>> s(n);
	rep(i, 0, n) {
		s[i] = read();
	}

	vi l = {-1}, r = {-1}, x = {0};
	l.reserve(K * n);
	r.reserve(K * n);
	x.reserve(K * n);
	rep(i, 0, n) {
		upd(s[i] ^ t, l, r, x, 1, k);
	}

	int q;
	input(q);
	while (q--) {
		int i, j;
		input(i, j);

		i--;
		j--;

		upd(s[i] ^ t, l, r, x, -1, k);
		s[i][j] = !s[i][j];
		upd(s[i] ^ t, l, r, x, 1, k);

		if (get(s[i] ^ t, l, r, x, m, k)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
