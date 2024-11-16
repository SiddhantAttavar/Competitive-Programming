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
const int MOD =  998244353;

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> pref(n + 1, 0);
	range(i, 0, n) {
		pref[i + 1] = pref[i] ^ a[i];
	}

	vector<int> v(30, 0);
	int res = 0;
	range(i, 0, n) {
		range(j, 0, 30) {
			int x = ((i + 1) * (1ll << j)) % MOD;
			if ((1ll << j) & pref[i + 1]) {
				res = (res + x * (i + 1 - v[j])) % MOD;
				v[j]++;
			}
			else {
				res = (res + x * v[j]) % MOD;
			}
		}
	}

	v = vector<int>(30, 0);
	for (int i = n; i > 0; i--) {
		range(j, 0, 30) {
			int x = (i * (1ll << j)) % MOD;
			if ((1ll << j) & pref[i]) {
				res = ((res - x * (n - i - v[j])) % MOD + MOD) % MOD;
				v[j]++;
			}
			else {
				res = ((res - x * v[j]) % MOD + MOD) % MOD;
			}
		}
	}
	print(res);
}
