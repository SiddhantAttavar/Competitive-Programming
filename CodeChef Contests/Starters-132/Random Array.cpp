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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pair<int, int>> a;
		vector<vector<int>> c(n);
		vector<vector<int>> d(n, {0});
		vector<int> b(n);
		range(i, 0, n) {
			int k;
			input(k);

			vector<int> v(k);
			arrPut(v);

			for (int j : v) {
				a.push_back({j, i});
			}
			b[i] = v[0];
		}
		sort(a.begin(), a.end());

		vector<int> z(a.size() + 1, 0);
		for (int i = a.size() - 1; i >= 0; i--) {
			int x, u;
			tie(x, u) = a[i];

			z[i] = z[i + 1];
			d[u].push_back(d[u].back());

			c[u].push_back(-x);
			int j = lower_bound(a.begin(), a.end(), make_pair(x + 1, 0ll)) - a.begin();
			int k = lower_bound(c[u].begin(), c[u].end(), -x) - c[u].begin();

			int t = (a.size() - j) - k;
			if (t == 0) {
				d[u].back() = (d[u].back() + x) % MOD;
				z[i] = (z[i] + x) % MOD;
				continue;
			}

			// print(x, u, z[j], d[u][k], t);
			int y = mod_div((z[j] - d[u][k] + MOD) % MOD, t);
			y = (y + x) % MOD;
			// print(x, u, y);
			d[u].back() = (d[u].back() + y) % MOD;
			z[i] = (z[i] + y) % MOD;
		}

		int x = 0;
		range(i, 0ll, n) {
			x += c[i].size();
		}
		print(mod_div(z[0], x));
	}
}
