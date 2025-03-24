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

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int32_t main() {
	setup();

	int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}

	int k, n, l;
	input(k, n, l);

	string s;
	input(s);

	int res = 1, x = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'O') {
			x++;
			continue;
		}

		if (x < k) {
			res = 0;
			break;
		}

		res = res * mod_div(fact[x], fact[k] * fact[x - k] % MOD) % MOD;
		x -= k;
	}

	if (x > 00) {
		print(0);
	}
	else {
		print(mod_pow(res, l));
	}
}
