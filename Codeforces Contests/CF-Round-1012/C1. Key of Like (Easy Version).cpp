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
	int N = 1e5;
	vector<int> fact(N + 1, 1);
	rep(i, 2ll, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, l, k;
		input(n, l, k);

		rep(i, 0, n) {
			int a = 0, b = 0;
			rep(j, 0, i + 1) {
				int k = mod_div(fact[i], fact[j] * fact[i - j] % MOD);
				// print(i, j, k);
				a = (a + k * j) % MOD;
				b = (b + k) % MOD;
			}
			// print(a, b);
			cout << mod_div(a, b) << ' ';
		}
		cout << endl;
	}
}
