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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res =  res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int32_t main() {
	const int N = 5e3;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, e, q;
		input(n, e, q);

		vector<int> a(n);
		arrput(a);

		rep(i, 0, n) {
			a[i] -= i;
		}

		vector<vector<int>> v(n);
		map<int, int> m;
		rep(j, 0, q) {
			int i, x;
			input(i, x);
			i--;
			v[i].push_back(x - i);
			m[x - 1]++;
		}

		vector<int> res(n);
		rep(i, 0, n) {
			sort(v[i].begin(), v[i].end());
			res[i] = i * fact[q] % MOD;

			vector<int> l, r;
			rep(j, 0, i) {
				l.insert(l.end(), v[j].begin(), v[j].end());
			}
			rep(j, i + 1, n) {
				r.insert(r.end(), v[j].begin(), v[j].end());
			}
			sort(l.begin(), l.end());
			sort(r.begin(), r.end());

			for (int k : l) {
				int s = lower_bound(r.begin(), r.end(), k) - r.begin() + lower_bound(v[i].begin(), v[i].end(), k) - v[i].begin();
				int t = l.end() - lower_bound(l.begin(), l.end(), k);
				int u = upper_bound(r.begin(), r.end(), k) - lower_bound(r.begin(), r.end(), k);
				int z = 0;
				if (s > 0) {
					z = mod_div(s * fact[q] % MOD, (s + t) * (s + t - 1) % MOD);
				}
				else if (a[i] <= k) {
					z = mod_div(fact[q], t);
				}
				// print(i, k + i, z, s, t);
				res[i] = (res[i] + k * z) % MOD;
			}

			for (int k : v[i]) {
				int t = v[i].size() + l.end() - lower_bound(l.begin(), l.end(), k) + upper_bound(r.begin(), r.end(), k) - r.begin();
				int z = 0;
				z = mod_div(fact[q], t);
				// print(i, k + i, z, t);
				res[i] = (res[i] + k * z) % MOD;
			}

			for (int k : r) {
				int s = lower_bound(r.begin(), r.end(), k) - r.begin() + lower_bound(v[i].begin(), v[i].end(), k) - v[i].begin();
				int t = l.end() - lower_bound(l.begin(), l.end(), k);
				int u = upper_bound(r.begin(), r.end(), k) - lower_bound(r.begin(), r.end(), k);
				int z = 0;
				if (s > 0) {
					z = mod_div(t * fact[q] % MOD, (s + t) * (u + s + t) % MOD);
				}
				else if (a[i] >= k) {
					z = mod_div(fact[q], t);
				}
				// print(i, k + i, z, s, t);
				res[i] = (res[i] + k * z) % MOD;
			}

			int t = v[i].size() + l.end() - lower_bound(l.begin(), l.end(), a[i]) + upper_bound(r.begin(), r.end(), a[i]) - r.begin();
			if (t == 0) {
				res[i] = (res[i] + a[i] * fact[q]) % MOD;
			}
		}
		arrprint(res);
	}
}
