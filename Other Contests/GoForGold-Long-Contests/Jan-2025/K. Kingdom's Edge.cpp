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

int query(int i) {
	print(1, i + 1);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int n, x;
	input(n, x);

	if (n == 1) {
		print(2, query(0) == x);
		return 0;
	}

	int l = 0, r = n / 2 - 1, res = -1, p = -1, q = n / 2;
	while (l <= r) {
		int m = (l + r) / 2;
		if (query(2 * m + 1) == x) {
			res = 2 * m + 1;
			break;
		}
		else if (query(2 * m + 1) < x) {
			l = m + 1;
			p = m;
		}
		else {
			r = m - 1;
			q = m;
		}
	}

	if (res != -1) {
		print(2, res + 1);
		return 0;
	}

	int k = query(2 * q);

	if (k == x) {
		print(2, 2 * q + 1);
		return 0;
	}

	l = 0, r = n / 2 - 1, p = -1, q = n / 2;
	while (l <= r) {
		int m = (l + r) / 2;
		if (query(2 * m + 1) < k) {
			l = m + 1;
			p = m;
		}
		else {
			r = m - 1;
			q = m;
		}
	}

	if (query(2 * q) == x) {
		print(2, 2 * q + 1);
	}
	else {
		print(2, 0);
	}
}
