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

int solve(vector<int> &a, int x, int y) {
	int n = a.size();
	int l = 0, r = n - 1;
	while (l < n and a[l] != y) {
		l++;
	}
	while (r >= 0 and a[r] != y) {
		r--;
	}

	range(i, l + 1, r) {
		if (a[i] == x) {
			return 0;
		}
	}

	int p = l - 1, q = r + 1;
	while (p >= 0 and a[p] != x) {
		p--;
	}
	while (q < n and a[q] != x) {
		q++;
	}
	return (l - p) * (q - r);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		print(n * (n + 1) / 2 - (solve(a, 3, 1) + solve(a, 1, 2) + solve(a, 2, 3)));
	}
}
