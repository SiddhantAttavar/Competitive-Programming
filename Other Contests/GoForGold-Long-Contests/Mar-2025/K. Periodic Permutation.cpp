#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e8 + 7; //998244353;

int mod_pow(int a, int b) {
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

int check(vector<int> &p) {
	vector<int> a(p.begin(), p.end());
	int c = 0;
	do {
		c++;
		vector<int> b(a.size());
		rep(i, 0, a.size()) {
			b[i] = a[a[i]];
		}
		a = b;
	} while (a != p and c < 1000);
	if (c == 1000) {
		return -1;
	}
	return c;
}

int32_t main() {
	int N = 1e6;
	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
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

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n);
		arrput(p);
		rep(i, 0, n) {
			p[i]--;
		}

		bool flag = true;
		vector<bool> v(n, false);
		map<int, int> m;
		rep(i, 0, n) {
			if (v[i]) {
				continue;
			}

			v[i] = true;
			int u = p[i];
			int x = 1;
			while (u != i) {
				v[u] = true;
				x++;
				u = p[u];
			}

			if (x == 1) {
				continue;
			}

			vector<bool> b(x, false);
			b[1] = true;
			u = 2 % x;
			int c = 1;
			while (!b[u]) {
				b[u] = true;
				u = u * 2 % x;
				c++;
			}

			if (u != 1) {
				flag = false;
				break;
			}

			map<int, int> v;
			while (c > 1) {
				v[spf[c]]++;
				c /= spf[c];
			}

			for (pair<int, int> p : v) {
				m[p.first] = max(m[p.first], p.second);
			}
		}

		if (!flag) {
			// assert(check(p) == -1);
			print(-1);
			continue;
		}

		int res = 1;
		for (pair<int, int> p : m) {
			rep(i, 0, p.second) {
				res = res * p.first % MOD;
			}
		}
		print(res);
		// cout.flush();
		// assert(check(p) == res);
	}
}
