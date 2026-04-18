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

int get(int a, int b) {
	int c = 0;
	rep(x, 0, a + 1) {
		rep(y, 0, a + 1) {
			int z = b ^ x ^ y;
			if (x + y + z == a) {
				c++;
			}
		}
	}
	return c;
}

int32_t main() {
	map<int, vector<pii>> f;
	rep(a, 0, 10) {
		rep(b, 0, 10) {
			f[get(a, b)].push_back({a, b});
		}
	}
	f.erase(0);
	for (auto [k, v] : f) {
		print(k);
		for (auto [i, j] : v) {
			print(i, j);
		}
		print("");
	}
	setup();
	int n, m;
	input(n, m);

	vi a(n), b(m);
	arrput(a);
	arrput(b);

	vector<pii> v;
	for (int i : a) {
		v.push_back({i, m});
	}
	rep(j, 0, m) {
		v.push_back({b[j], j});
	}
	sort(all(v));

	vi res(21, 0);
	res[0] = n * m;
	rep(i, 0, 20) {
		int z = 1ll << i;
		vi f(4 * z, 0);
		for (auto [x, j] : v) {
			if (j < m) {
				f[x % z]++;
				continue;
			}

			if (x < z - 1) {
				continue;
			}
			int y = x - 2 * (z - 1);
			y = ((y % z) + z) % z;
			print(x, y, z);
			res[i] -= f[y];
			res[i + 1] += f[y];
		}
	}

	int z = 0, k = 1, t = 1;
	rep(i, 0, 20) {
		z = (z + k) % MOD;
		t = t * mpow(z, res[i + 1]) % MOD;
		k = k * 3 % MOD;
	}
	print(t);
}
