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
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		if (k == 1) {
			if (n == 1) {
				print("YES");
				print(1);
			}
			else {
				print("NO");
			}
			continue;
		}

		if (n % 2 == 0 and k % 2 == 1) {
			print("NO");
			continue;
		}

		if (n == 1) {
			print("NO");
			continue;
		}

		if (n < 20) {
			int c = 1;
			rep(i, 1, n + 1) {
				c *= i;
			}
			if (c < k) {
				print("NO");
				continue;
			}
		}

		vector<vector<int>> res, v;
		set<int> s;
		if (k % 2 == 1) {
			vector<int> a(n), b(n), c(n);
			for (int i = 0; i + 1 < n; i += 2) {
				a[i] = i + 1;
				a[i + 1] = i + 2;
				b[i] = n / 2 + 1 - i / 2;
				b[i + 1] = n - i / 2;
				c[i] = n - i / 2;
				c[i + 1] = n / 2 - i / 2;
			}
			a[n - 1] = n;
			b[n - 1] = 1;
			c[n - 1] = n / 2 + 1;
			res = v = {a, b, c};
			k -= 3;
		}

		vector<int> a(n);
		rep(i, 0, n) {
			a[i] = i + 1;
		}
		while (k) {
			vector<int> b(n);
			rep(i, 0, n) {
				b[i] = n + 1 - a[i];
			}
			if (a > b) {
				break;
			}
			if (find(v.begin(), v.end(), a) == v.end() and find(v.begin(), v.end(), b) == v.end()) {
				res.push_back(a);
				res.push_back(b);
				k -= 2;
			}
			if (!next_permutation(a.begin(), a.end())) {
				break;
			}
		}

		if (k) {
			print("NO");
			continue;
		}

		print("YES");
		for (vector<int> v : res) {
			arrprint(v);
		}

		// rep(i, 0, n) {
		// 	int c = 0;
		// 	for (vector<int> v : res) {
		// 		c += v[i];
		// 	}
		// 	assert(2 * c == (n + 1) * res.size());
		// }

		// rep(i, 0, res.size()) {
		// 	rep(j, i + 1, res.size()) {
		// 		assert(res[i] != res[j]);
		// 	}
		// }
	}
}
