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

int solve(vector<int> a) {
	arrPrint(a);
	if (a.size() == 1) {
		return a[0];
	}
	vector<int> b(a.size() - 1);
	range(i, 0, a.size() - 1) {
		b[i] = a[i] ^ a[i + 1];
	}
	return solve(b);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> f(n, vector<int>(n, 0));
	arrPut(f[0]);
	range(i, 1, n) {
		range(j, 0, n - 1) {
			f[i][j] = f[i - 1][j] ^ f[i - 1][j + 1];
		}
	}

	vector<vector<int>> g(n, vector<int>(n, 0));
	range(i, 0, n) {
		g[i][i] = f[0][i];
	}
	range(l, 2, n + 1) {
		range(i, 0, n - l + 1) {
			int j = i + l - 1;
			g[i][j] = max({f[j - i][i], g[i][j - 1], g[i + 1][j]});
		}
	}

	int q;
	input(q);
	while (q--) {
		int l, r;
		input(l, r);
		print(g[l - 1][r - 1]);
	}
}
