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

int brute(vector<int> &a) {
	int n = a.size();
	vector<int> v(n);
	rep(i, 0, n) {
		v[i] = i + 1;
	}

	int res = 0;
	do {
		set<int> s;
		int x = 1;
		bool flag = true;
		rep(i, 0, n) {
			s.insert(v[i]);
			while (s.count(x)) {
				x++;
			}
			if (a[i] != x) {
				flag = false;
				break;
			}
		}
		res += flag;
	} while (next_permutation(v.begin(), v.end()));
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		bool flag = true;
		rep(i, 1, n) {
			if (a[i] < a[i - 1]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		rep(i, 0, n) {
			if (a[i] > i + 2) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		if (a[n - 1] != n + 1) {
			print(0);
			continue;
		}

		vector<int> b(n, 0);
		if (a[0] == 2) {
			b[0] = 1;
		}

		rep(i, 1, n) {
			if (a[i] != a[i - 1]) {
				b[i] = a[i - 1];
			}
		}

		vector<int> c(n, n + 1);
		for (int i = n - 2; i >= 0; i--) {
			c[i] = c[i + 1];
			if (b[i + 1] > 0) {
				c[i] = b[i + 1];
			}
		}

		int x = 0;
		int res = 1;
		rep(i, 0, n) {
			if (b[i] == 0) {
				x++;
				continue;
			}

			rep(j, b[i] + 1, c[i]) {
				res = (res * x) % MOD;
				x--;
			}
		}
		print(res);
		// assert(res == brute(a));
	}
}
