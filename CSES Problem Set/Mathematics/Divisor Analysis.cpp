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

int modPow(int a, int b, int m = MOD) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % m;
		}

		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int modDiv(int a, int b) {
	return (a * modPow(b, MOD - 2)) % MOD;
}

int32_t main() {
	setup();

	int n;
	input(n);

	int a = 1, b = 1, c = 1, d = 1, p = 1;
	bool flag = false;
	range(i, 0, n) {
		int x, k;
		input(x, k);

		a = (a * (k + 1)) % MOD;
		if (k & 1 and !flag) {
			d = (d * ((k + 1) / 2)) % (MOD - 1);
			flag = true;
		}
		else {
			d = (d * (k + 1)) % (MOD - 1);
		}
		b = (b * modDiv((modPow(x, k + 1) + MOD - 1) % MOD, x - 1)) % MOD;
		c = (c * modPow(x, k)) % MOD;
		if (k % 2 == 0 and !flag) {
			p = (p * modPow(x, k / 2)) % MOD;
		}
	}
	if (flag) {
		print(a, b, modPow(c, d));
	}
	else {
		print(a, b, modPow(p, d));
	}
}
