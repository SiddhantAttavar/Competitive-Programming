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
const int MOD = (int) 1e9 + 7; //998244353

int t = 0;
int query(int l, int r) {
	t++;
	assert(t <= 150);
	print("xor", l, r);
	cout.flush();

	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		t = 0;
		int n;
		input(n);

		int k = query(1, n);
		if (k != 0) {
			int l = 1, r = n, a = 1, b;
			while (l <= r) {
				int m = (l + r) / 2;
				if (query(1, m) == 0) {
					l = m + 1;
				}
				else {
					a = m;
					r = m - 1;
				}
			}

			l = a + 1, r = n, b = a + 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (query(a + 1, m) == 0) {
					l = m + 1;
				}
				else {
					b = m;
					r = m - 1;
				}
			}

			print("ans", a, b, k ^ a ^ b);
			cout.flush();
			continue;
		}

		int x = 0;
		for (int i = 59; i >= 0; i--) {
			int y = x | (1ll << i);
			if (y <= n and query(y, n)) {
				x = y;
			}
		}
		assert(query(x, x) == x);

		if (query(1, x) == x) {
			int a = x;
			int l = a + 1, r = n, b = a + 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (query(a, m) == a) {
					l = m + 1;
				}
				else {
					b = m;
					r = m - 1;
				}
			}

			assert(query(b, b) == b);
			print("ans", a, b, a ^ b);
			cout.flush();
			continue;
		}

		if (query(x, n) == x) {
			int c = x;
			int l = 1, r = c - 1, b = c - 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (query(m, c) == c) {
					r = m - 1;
				}
				else {
					b = m;
					l = m + 1;
				}
			}

			assert(query(b, b) == b);
			print("ans", b ^ c, b, c);
			cout.flush();
			continue;
		}

		int b = x;
		int l = 1, r = b - 1, a = b - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (query(m, b) == b) {
				r = m - 1;
			}
			else {
				a = m;
				l = m + 1;
			}
		}

		assert(query(a, a) == a);
		print("ans", a, b, a ^ b);
		cout.flush();
	}
}
