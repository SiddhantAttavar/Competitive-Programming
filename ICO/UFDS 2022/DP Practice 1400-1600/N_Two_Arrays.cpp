#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long


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

int mod_inv(int a) {
	return mod_pow(a, MOD - 2);
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	int x = 2 * m - 1;

	vector<int> fact(n + x), fact_inv(n + x);
	fact[0] = 1;
	fact_inv[0] = 1;
	range(i, 0, n + x - 1) {
		fact[i + 1] = (fact[i] * (i + 1)) % MOD;
		fact_inv[i + 1] = mod_inv(fact[i + 1]);
	}

	int res = 0;
	range(i, 0, n) {
		res = (res + ((fact[i + x] * fact_inv[i]) % MOD * fact_inv[x]) % MOD) % MOD;
	}

	print(res);
}
