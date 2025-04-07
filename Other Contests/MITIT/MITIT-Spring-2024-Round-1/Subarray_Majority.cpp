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

int solve(int i, vector<int> &a) {
	vector<int> m(3);
	int x = 0;
	for (int j = i - 1; j >= 0; j--) {
		m[a[j] - 1]++;
		x = max(x, m[a[j] - 1]);
		if (2 * x < (i - j)) {
			return 0;
		}
	}

	if (i == a.size()) {
		return 1;
	}

	a[i] = 1;
	int res = solve(i + 1, a);
	a[i] = 2;
	res = (res + solve(i + 1, a)) % MOD;
	a[i] = 3;
	return (res + solve(i + 1, a)) % MOD;
}

int32_t main() {
	setup();

	vector<int> res = {0, 3, 9, 21, 51, 111, 249, 531, 1155, 2433, 5205, 10887, 23043, 47979, 100809, 209217, 437283, 905283, 1884717, 3894195, 8082879, 16674285, 34526799, 71132079, 147005679, 302525559};

	int n;
	input(n);

	print(res[n] % MOD);
}
