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
int modDiv(int a, int b) {
	int x = MOD - 2;
	int res = 1;
	while (x) {
		if (x & 1) {
			res = (res * b) % MOD;
		}

		b = (b * b) % MOD;
		x >>= 1;
	}
	return (a * res) % MOD;
}

int32_t main() {
	setup();
	int N = 1e6;
	vector<int> fact(N + 1, 1);
	range(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}
		
	int n;
	input(n);

	if (n % 2) {
		print(0);
		return 0;
	}

	print(modDiv((fact[n - 1] * 2) % MOD, (fact[n / 2 + 1] * fact[n / 2 - 1]) % MOD));
}
