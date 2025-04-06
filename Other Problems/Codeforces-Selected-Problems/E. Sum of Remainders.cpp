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
	setup();

	int n, m;
	input(n, m);

	int res = (m % MOD) * (n % MOD) % MOD;
	for (int i = 1; i * i <= n; i++) {
		if (i <= m) {
			res = (res - (((n / i) * i) % MOD) + MOD) % MOD;
		}
		int l = max(i + 1, n / (i + 1) + 1), r = min(m, n / i);
		if (l <= r) {
			res = (res - ((((l + r) % MOD) * ((r - l + 1) % MOD) % MOD * ((MOD + 1) / 2)) % MOD * i) % MOD + MOD) % MOD;
		}
	}
	print(res);
}
